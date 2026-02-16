#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind11_json.hpp"

#include "reader.hpp"


#include "spdlog/spdlog.h"
#include "spdlog/sinks/base_sink.h"

namespace py = pybind11;

using namespace hue;

class python_hue_sink : public spdlog::sinks::base_sink<std::mutex> {
public:
    explicit python_hue_sink(std::string name) : name(name) {
    }
protected:
    void sink_it_(const spdlog::details::log_msg& msg) override {
        py::gil_scoped_acquire gil;

       
        int level = map(msg.level);

		std::string text = { msg.payload.data(), msg.payload.size() };

        py::object logging = py::module_::import("logging");
        py::object logger = logging.attr("getLogger")(name);
        logger.attr("log")(level, text);
    }

    void flush_() override {}

private:
    std::string name;

    static int map(spdlog::level::level_enum lvl) {
        switch (lvl) {
        case spdlog::level::trace:    return 5;
        case spdlog::level::debug:    return 10;
        case spdlog::level::info:     return 20;
        case spdlog::level::warn:     return 30;
        case spdlog::level::err:      return 40;
        case spdlog::level::critical: return 50;
        default: return 20;
        }
    }
};

class PyEventIterator {
public:
    PyEventIterator(std::shared_ptr<reader> r, int max_timeout, py::object stop_event)
        : _reader(std::move(r)), stop_event(std::move(stop_event)), max_timeout(max_timeout) {
    }

    py::object next() {
        py::gil_scoped_release release;    // release GIL during blocking wait
        auto start = std::chrono::steady_clock::now();
        auto deadline = (max_timeout > 0)
            ? start + std::chrono::milliseconds{max_timeout}
            : std::chrono::steady_clock::time_point::max();
        while (true) {
            auto h = _reader->acquire();
            if (!h) {
                std::this_thread::sleep_for(std::chrono::milliseconds{ 10 });
                continue;
            }

            std::pair<hue::game_state, event> item;
            // finite timeout, never infinite
            bool ok = h->wait_dequeue_timed(item, std::chrono::milliseconds{ 100 });

            py::gil_scoped_acquire acquire; // point where KeyboardInterrupt is delivered
            if (PyErr_CheckSignals() != 0) {
                throw py::error_already_set();
            }
            if(!stop_event.is_none() && py::cast<bool>(stop_event.attr("is_set")())) {
                return py::str("stop");
            }
            if (std::chrono::steady_clock::now() >= deadline) {
                return py::str("timeout");
            }


            if (!ok) {
                continue;
            }

            py::object o = py::cast(item.second.json());
            return py::make_tuple(std::move(item.first), std::move(o));
        }
    }

private:
    std::shared_ptr<reader> _reader;
    int max_timeout;
    py::object stop_event;
};

std::shared_ptr<efsw::FileWatcher> get_global_watcher() {
    // Function-local static ensures thread-safe lazy initialization in C++11+
    static auto watcher = std::make_shared<efsw::FileWatcher>();
    return watcher;
}

class py_reader {
public:
    explicit py_reader(const std::string& journal_dir)
        : journal_dir(journal_dir), _reader(std::make_shared<hue::reader>(journal_dir)), watcher(get_global_watcher()) {
    }

    ~py_reader() {
        watcher->removeWatch(id);
    }

    void start() {
        spdlog::trace("starting new watch {}", journal_dir);
        _reader->replay_file();
        id = watcher->addWatch(journal_dir, _reader.get());
    }

    py_reader& __enter__() {
        start();
        watcher->watch();
        return *this;
    }

    void __exit__(py::object exc_type, py::object exc_value, py::object traceback) {
        watcher->removeWatch(id);
    }

    PyEventIterator events(int max_timeout, py::object stop_event) {
        return PyEventIterator(_reader, max_timeout, stop_event);
    }

private:
    std::string journal_dir;
    std::shared_ptr<hue::reader> _reader;
    std::shared_ptr<efsw::FileWatcher> watcher;
    efsw::WatchID id;
    std::thread thr;
};

PYBIND11_MODULE(_core, m, py::mod_gil_not_used()) {
    auto sink = std::make_shared<python_hue_sink>("raxxla._core");


    auto l = spdlog::default_logger();
    l->sinks().clear();
    l->sinks().push_back(sink);
    spdlog::set_default_logger(l);
    spdlog::set_level(spdlog::level::trace); // let python filter levels

    py::class_<py_reader>(m, "Reader")
        .def(py::init<const std::string&>())
		.def("events", &py_reader::events)
        .def("__enter__", &py_reader::__enter__)
        .def("__exit__", &py_reader::__exit__);

    py::class_<PyEventIterator>(m, "EventIterator")
        .def("__iter__", [](PyEventIterator& it) -> PyEventIterator& {
            return it;
        })
        .def("__next__", &PyEventIterator::next);

    // suit
    py::class_<hue::suit>(m, "Suit")
        .def_property_readonly("suit_id",        &suit::get_suit_id)
        .def_property_readonly("edmc_name",      &suit::get_edmc_name)
        .def_property_readonly("loc_name",       &suit::get_loc_name)
        .def_property_readonly("name",           &suit::get_name)
        .def_property_readonly("mods",           &suit::get_mods)
        .def_property_readonly("id",             &suit::get_id);


    // suit_loadout
    py::class_<suit_loadout>(m, "SuitLoadout")
        .def_property_readonly("loadout_slot_id", &suit_loadout::get_loadout_slot_id)
        .def_property_readonly("suit",            &suit_loadout::get_current_suit,
                               py::return_value_policy::reference_internal)
        .def_property_readonly("name",            &suit_loadout::get_name)
        .def_property_readonly("slots",           &suit_loadout::get_slots);


    // backpack_contents
    py::class_<backpack_contents>(m, "BackpackContents")
        .def_property_readonly("component",  &backpack_contents::get_component)
        .def_property_readonly("consumable", &backpack_contents::get_consumable)
        .def_property_readonly("item",       &backpack_contents::get_item)
        .def_property_readonly("data",       &backpack_contents::get_data);


    // powerplay_info
    py::class_<powerplay_info>(m, "PowerplayInfo")
        .def_property_readonly("power",        &powerplay_info::get_power)
        .def_property_readonly("rank",         &powerplay_info::get_rank)
        .def_property_readonly("merits",       &powerplay_info::get_merits)
        .def_property_readonly("votes",        &powerplay_info::get_votes)
        .def_property_readonly("time_pledged", &powerplay_info::get_time_pledged);


    // game_state
    py::class_<game_state>(m, "State")
        .def_property_readonly("game_language",     &game_state::get_game_language)
        .def_property_readonly("game_version",      &game_state::get_game_version)
        .def_property_readonly("game_build",        &game_state::get_game_build)

        .def_property_readonly("captain",           &game_state::get_captain)
        .def_property_readonly("cargo",             &game_state::get_cargo)
        .def_property_readonly("credits",           &game_state::get_credits)
        .def_property_readonly("fid",               &game_state::get_fid)
        .def_property_readonly("horizons",          &game_state::get_horizons)
        .def_property_readonly("odyssey",           &game_state::get_odyssey)
        .def_property_readonly("loan",              &game_state::get_loan)

        .def_property_readonly("raw",               &game_state::get_raw)
        .def_property_readonly("manufactured",      &game_state::get_manufactured)
        .def_property_readonly("encoded",           &game_state::get_encoded)

        .def_property_readonly("engineers",         &game_state::get_engineers)
        .def_property_readonly("rank",              &game_state::get_rank)
        .def_property_readonly("reputation",        &game_state::get_reputation)
        .def_property_readonly("statistics",        &game_state::get_statistics)

        .def_property_readonly("role",              &game_state::get_role)

        .def_property_readonly("friends",           &game_state::get_friends)

        .def_property_readonly("ship_id",           &game_state::get_ship_id)
        .def_property_readonly("ship_ident",        &game_state::get_ship_ident)
        .def_property_readonly("ship_name",         &game_state::get_ship_name)
        .def_property_readonly("ship_type",         &game_state::get_ship_type)
        .def_property_readonly("hull_value",        &game_state::get_hull_value)
        .def_property_readonly("modules_value",     &game_state::get_modules_value)
        .def_property_readonly("unladen_mass",      &game_state::get_unladen_mass)
        .def_property_readonly("cargo_capacity",    &game_state::get_cargo_capacity)
        .def_property_readonly("max_jump_range",    &game_state::get_max_jump_range)
        .def_property_readonly("fuel_capacity",     &game_state::get_fuel_capacity)
        .def_property_readonly("rebuy",             &game_state::get_rebuy)

        .def_property_readonly("modules",           &game_state::get_modules)
        .def_property_readonly("cargo_json",        &game_state::get_cargo_json)
        .def_property_readonly("route",             &game_state::get_route)

        .def_property_readonly("is_docked",         &game_state::get_is_docked)
        .def_property_readonly("on_foot",           &game_state::get_on_foot)

        .def_property_readonly("component",         &game_state::get_component)
        .def_property_readonly("item",              &game_state::get_item)
        .def_property_readonly("consumable",        &game_state::get_consumable)
        .def_property_readonly("data",              &game_state::get_data)

        .def_property_readonly("backpack",          &game_state::get_backpack,
                               py::return_value_policy::reference_internal)
        .def_property_readonly("backpack_json",     &game_state::get_backpack_json)
        .def_property_readonly("ship_locker_json",  &game_state::get_ship_locker_json)

        .def_property_readonly("suits",             &game_state::get_suits)
        .def_property_readonly("suit_loadouts",     &game_state::get_suit_loadouts)
        .def_property_readonly("suit_current",      &game_state::get_suit_current)
        .def_property_readonly("suit_loadout_current", &game_state::get_suit_loadout_current)

        .def_property_readonly("taxi",              &game_state::get_taxi)
        .def_property_readonly("dropship",          &game_state::get_dropship)

        .def_property_readonly("star_pos",          &game_state::get_star_pos)
        .def_property_readonly("system_address",    &game_state::get_system_address)
        .def_property_readonly("system_name",       &game_state::get_system_name)
        .def_property_readonly("system_population", &game_state::get_system_population)
        .def_property_readonly("body",              &game_state::get_body)
        .def_property_readonly("body_id",           &game_state::get_body_id)
        .def_property_readonly("body_type",         &game_state::get_body_type)
        .def_property_readonly("station_name",      &game_state::get_station_name)
        .def_property_readonly("station_type",      &game_state::get_station_type)
        .def_property_readonly("market_id",         &game_state::get_market_id)

        .def_property_readonly("nav_route",         &game_state::get_nav_route)

        .def_property_readonly("power_play",        &game_state::get_power_play,
                               py::return_value_policy::reference_internal);

    py::class_<hue::module_modifier>(m, "ModuleModifier")
        .def_property_readonly("label", &hue::module_modifier::get_label)
        .def_property_readonly("less_is_good", &hue::module_modifier::get_less_is_good)
        .def_property_readonly("original_value", &hue::module_modifier::get_original_value)
        .def_property_readonly("value", &hue::module_modifier::get_value)
        .def_property_readonly("value_str", &hue::module_modifier::get_value_str)
        .def_property_readonly("value_str_localised", &hue::module_modifier::get_value_str_localised);

    // module_engineering
    py::class_<hue::module_engineering>(m, "ModuleEngineering")
        .def_property_readonly("blueprint_id", &hue::module_engineering::get_blueprint_id)
        .def_property_readonly("blueprint_name", &hue::module_engineering::get_blueprint_name)
        .def_property_readonly("engineer", &hue::module_engineering::get_engineer)
        .def_property_readonly("engineer_id", &hue::module_engineering::get_engineer_id)
        .def_property_readonly("experimental_effect", &hue::module_engineering::get_experimental_effect)
        .def_property_readonly("experimental_effect_localised", &hue::module_engineering::get_experimental_effect_localised)
        .def_property_readonly("level", &hue::module_engineering::get_level)
        .def_property_readonly("modifiers", &hue::module_engineering::get_modifiers)
        .def_property_readonly("quality", &hue::module_engineering::get_quality);

    // fuel_tanks
    py::class_<hue::fuel_tanks>(m, "FuelTanks")
        .def_property_readonly("main", &hue::fuel_tanks::get_main)
        .def_property_readonly("reserve", &hue::fuel_tanks::get_reserve);

    // module
    py::class_<hue::module>(m, "Module")
        .def(py::init<const hue::module&>())   // converting ctor
        .def_property_readonly("ammo_in_clip", &hue::module::get_ammo_in_clip)
        .def_property_readonly("ammo_in_hopper", &hue::module::get_ammo_in_hopper)
        .def_property_readonly("engineering", &hue::module::get_engineering,
            py::return_value_policy::reference_internal)
        .def_property_readonly("health", &hue::module::get_health)
        .def_property_readonly("item", &hue::module::get_item)
        .def_property_readonly("on", &hue::module::get_on)
        .def_property_readonly("priority", &hue::module::get_priority)
        .def_property_readonly("slot", &hue::module::get_slot)
        .def_property_readonly("value", &hue::module::get_value);

}
