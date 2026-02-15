#include "reader.hpp"

#include <string>
#include <iostream>
#include <vector>
#include "fmt/format.h"
#include "spdlog/spdlog.h"

#include "registry.hpp"


#include "re2/re2.h"
#include <filesystem>
#include <sys/stat.h>

#ifdef __APPLE__
#include "date/date.h"
#endif

#include "events/Shutdown.hpp"
namespace fs = std::filesystem;


#include "events/ApproachBody.hpp"
#include "events/Backpack.hpp"
#include "events/BackpackChange.hpp"
#include "events/BookDropship.hpp"
#include "events/BookTaxi.hpp"
#include "events/BuyAmmo.hpp"
#include "events/BuyDrones.hpp"
#include "events/BuyExplorationData.hpp"
#include "events/BuyMicroResources.hpp"
#include "events/BuyTradeData.hpp"
#include "events/CancelDropship.hpp"
#include "events/CancelTaxi.hpp"
#include "events/Cargo.hpp"
#include "events/CargoTransfer.hpp"
#include "events/CarrierBankTransfer.hpp"
#include "events/CarrierBuy.hpp"
#include "events/CarrierDecommission.hpp"
#include "events/CarrierJump.hpp"
#include "events/CarrierJumpCancelled.hpp"
#include "events/CarrierJumpRequest.hpp"
#include "events/CarrierStats.hpp"
#include "events/ChangeCrewRole.hpp"
#include "events/CollectCargo.hpp"
#include "events/CommunityGoalReward.hpp"
#include "events/CrewHire.hpp"
#include "events/Disembark.hpp"
#include "events/Docked.hpp"
#include "events/DropshipDeploy.hpp"
#include "events/EjectCargo.hpp"
#include "events/Embark.hpp"
#include "events/EngineerContribution.hpp"
#include "events/EngineerCraft.hpp"
#include "events/EngineerProgress.hpp"
#include "events/FCMaterials.hpp"
#include "events/FetchRemoteModule.hpp"
#include "events/Friends.hpp"
#include "events/FSDJump.hpp"
#include "events/JoinACrew.hpp"
#include "events/LeaveBody.hpp"
#include "events/Loadout.hpp"
#include "events/Location.hpp"
#include "events/Market.hpp"
#include "events/MarketBuy.hpp"
#include "events/MarketSell.hpp"
#include "events/MaterialCollected.hpp"
#include "events/MaterialDiscarded.hpp"
#include "events/Materials.hpp"
#include "events/MaterialTrade.hpp"
#include "events/MiningRefined.hpp"
#include "events/MissionAbandoned.hpp"
#include "events/MissionCompleted.hpp"
#include "events/ModuleBuy.hpp"
#include "events/ModuleInfo.hpp"
#include "events/ModuleSell.hpp"
#include "events/ModuleSellRemote.hpp"
#include "events/ModuleStore.hpp"
#include "events/ModuleSwap.hpp"
#include "events/Music.hpp"
#include "events/NavRoute.hpp"
#include "events/NewCommander.hpp"
#include "events/NpcCrewPaidWage.hpp"
#include "events/Outfitting.hpp"
#include "events/PayBounties.hpp"
#include "events/Powerplay.hpp"
#include "events/PowerplayFastTrack.hpp"
#include "events/PowerplayMerits.hpp"
#include "events/PowerplayRank.hpp"
#include "events/PowerplaySalary.hpp"
#include "events/Progress.hpp"
#include "events/Promotion.hpp"
#include "events/QuitACrew.hpp"
#include "events/Rank.hpp"
#include "events/RedeemVoucher.hpp"
#include "events/RefuelAll.hpp"
#include "events/Repair.hpp"
#include "events/RestockVehicle.hpp"
#include "events/Resupply.hpp"
#include "events/Resurrect.hpp"
#include "events/ScientificResearch.hpp"
#include "events/SearchAndRescue.hpp"
#include "events/SellDrones.hpp"
#include "events/SellExplorationData.hpp"
#include "events/SellMicroResources.hpp"
#include "events/SellShipOnRebuy.hpp"
#include "events/SetUserShipName.hpp"
#include "events/ShipLocker.hpp"
#include "events/Shipyard.hpp"
#include "events/ShipyardBuy.hpp"
#include "events/ShipyardSwap.hpp"
#include "events/ShipyardTransfer.hpp"
#include "events/SquadronCreated.hpp"
#include "events/SupercruiseEntry.hpp"
#include "events/SupercruiseExit.hpp"
#include "events/Synthesis.hpp"
#include "events/TechnologyBroker.hpp"
#include "events/Undocked.hpp"
#include "events/Fileheader.hpp"
#include "events/LoadGame.hpp"
#include "events/Commander.hpp"

using namespace std::chrono_literals;


namespace hue {
    static const RE2 RE_LOGFILE(
        R"(^Journal\.(\d{4}-\d{2}-\d{2}T\d{6})\.(\d{2})\.log$)"
    );
    static const RE2 RE_SHIP_ONFOOT(
        R"(^(FlightSuit|UtilitySuit_Class.|TacticalSuit_Class.|ExplorationSuit_Class.)$)"
    );

    static const RE2 RE_CANONICALISE(
        R"(\$(.+)_name;)"
        );
    static const RE2 RE_FC_JUMP_NAME(
        R"(^FC ([A-NP-Z0-9]{3})([A-NP-Z0-9]{3})$)"
        );

    static const RE2 RE_CATEGORY(
        R"(\$MICRORESOURCE_CATEGORY_(.+);)"
        );

    struct ShipData {
        int hullMass;
        double reserveFuelCapacity;
    };

    static const std::unordered_map<std::string, ShipData> ship_data = {
        {"Adder", {35, 0.36}},
        {"Alliance Challenger", {450, 0.77}},
        {"Alliance Chieftain", {400, 0.77}},
        {"Alliance Crusader", {500, 0.77}},
        {"Anaconda", {400, 1.07}},
        {"Asp Explorer", {280, 0.63}},
        {"Asp Scout", {150, 0.47}},
        {"Beluga Liner", {950, 0.81}},
        {"Cobra MkIII", {180, 0.49}},
        {"Cobra MkIV", {210, 0.51}},
        {"Cobra Mk V", {150, 0.49}},
        {"Corsair", {265, 0.41}},
        {"Diamondback Explorer", {260, 0.52}},
        {"Diamondback Scout", {170, 0.49}},
        {"Dolphin", {140, 0.50}},
        {"Eagle", {50, 0.34}},
        {"Federal Assault Ship", {480, 0.72}},
        {"Federal Corvette", {900, 1.13}},
        {"Federal Dropship", {580, 0.83}},
        {"Federal Gunship", {580, 0.82}},
        {"Fer-de-Lance", {250, 0.67}},
        {"Hauler", {14, 0.25}},
        {"Imperial Clipper", {400, 0.74}},
        {"Imperial Courier", {35, 0.41}},
        {"Imperial Cutter", {1100, 1.16}},
        {"Imperial Eagle", {50, 0.37}},
        {"Keelback", {180, 0.39}},
        {"Krait MkII", {320, 0.63}},
        {"Krait Phantom", {270, 0.63}},
        {"Mamba", {250, 0.50}},
        {"Mandalay", {230, 0.52}},
        {"Orca", {290, 0.79}},
        {"Panther Clipper Mk II", {1200, 1.11}},
        {"Python", {350, 0.83}},
        {"Python Mk II", {450, 0.83}},
        {"Sidewinder", {25, 0.30}},
        {"Type-10 Defender", {1200, 0.77}},
        {"Type-11 Prospector", {320, 0.60}},
        {"Type-6 Transporter", {155, 0.39}},
        {"Type-7 Transporter", {350, 0.52}},
        {"Type-8 Transporter", {400, 0.52}},
        {"Type-9 Heavy", {850, 0.77}},
        {"Viper MkIII", {50, 0.41}},
        {"Viper MkIV", {190, 0.46}},
        {"Vulture", {230, 0.57}}
    };

    static const std::unordered_map<std::string, std::string> ship_name_map = {
        {"adder", "Adder"},
        {"anaconda", "Anaconda"},
        {"asp", "Asp Explorer"},
        {"asp_scout", "Asp Scout"},
        {"belugaliner", "Beluga Liner"},
        {"cobramkiii", "Cobra MkIII"},
        {"cobramkiv", "Cobra MkIV"},
        {"cobramkv", "Cobra Mk V"},
        {"corsair", "Corsair"},
        {"clipper", "Panther Clipper"},
        {"cutter", "Imperial Cutter"},
        {"diamondback", "Diamondback Scout"},
        {"diamondbackxl", "Diamondback Explorer"},
        {"dolphin", "Dolphin"},
        {"eagle", "Eagle"},
        {"empire_courier", "Imperial Courier"},
        {"empire_eagle", "Imperial Eagle"},
        {"empire_fighter", "Imperial Fighter"},
        {"empire_trader", "Imperial Clipper"},
        {"federation_corvette", "Federal Corvette"},
        {"federation_dropship", "Federal Dropship"},
        {"federation_dropship_mkii", "Federal Assault Ship"},
        {"federation_gunship", "Federal Gunship"},
        {"federation_fighter", "F63 Condor"},
        {"ferdelance", "Fer-de-Lance"},
        {"hauler", "Hauler"},
        {"independant_trader", "Keelback"},
        {"independent_fighter", "Taipan Fighter"},
        {"krait_mkii", "Krait MkII"},
        {"krait_light", "Krait Phantom"},
        {"lakonminer", "Type-11 Prospector"},
        {"mamba", "Mamba"},
        {"mandalay", "Mandalay"},
        {"orca", "Orca"},
        {"panthermkii", "Panther Clipper Mk II"},
        {"python", "Python"},
        {"python_nx", "Python Mk II"},
        {"scout", "Taipan Fighter"},
        {"sidewinder", "Sidewinder"},
        {"testbuggy", "Scarab"},
        {"type6", "Type-6 Transporter"},
        {"type7", "Type-7 Transporter"},
        {"type8", "Type-8 Transporter"},
        {"type9", "Type-9 Heavy"},
        {"type9_military", "Type-10 Defender"},
        {"typex", "Alliance Chieftain"},
        {"typex_2", "Alliance Crusader"},
        {"typex_3", "Alliance Challenger"},
        {"viper", "Viper MkIII"},
        {"viper_mkiv", "Viper MkIV"},
        {"vulture", "Vulture"}
    };


    semantic_version coerce_semver(const std::string& s) {
        semantic_version out;

        std::string digits;
        digits.reserve(s.size());

        for (char c : s) {
            if (std::isdigit(c) || c == '.') digits.push_back(c);
            else digits.push_back('.');  // replace invalid chars
        }

        std::stringstream ss(digits);
        std::string tok;
        int nums[3] = {0,0,0};
        int i = 0;

        while (std::getline(ss, tok, '.') && i < 3) {
            if (!tok.empty())
                nums[i] = std::stoi(tok);
            i++;
        }

        out.major = nums[0];
        out.minor = nums[1];
        out.patch = nums[2];
        out.valid = true;
        return out;
    }

        bool event_valid_engineerprogress(const engineer_progress& e) {
        const bool engineers_present = e.engineers.has_value();
        const bool progress_present  = e.progress.has_value();

        // must have one of Engineers / Progress
        if (!(engineers_present || progress_present)) {
            spdlog::warn("EngineerProgress missing both 'Engineers' and 'Progress'");
            return false;
        }

        // cannot have both
        if (engineers_present && progress_present) {
            spdlog::warn("EngineerProgress has BOTH 'Engineers' and 'Progress'");
            return false;
        }

        // ---------- Engineers version (list) ----------
        if (engineers_present) {
            const auto& list = *e.engineers;

            if (list.empty()) {
                spdlog::warn("EngineerProgress 'Engineers' list is empty");
                return false; // matches Python
            }

            for (const auto& eng : list) {
                bool invited_or_known =
                    (eng.progress == "Invited" || eng.progress == "Known");

                // Required fields: Engineer, EngineerID, Rank, Progress, RankProgress
                bool missing_engineer   = eng.engineer.empty();
                bool missing_engineerid = (eng.engineer_id == 0); // Python just checks presence
                bool missing_progress   = eng.progress.empty();
                bool missing_rank       = !eng.rank.has_value();
                bool missing_rankprog   = !eng.rank_progress.has_value();

                // special exception for missing Rank / RankProgress
                if (invited_or_known) {
                    missing_rank = false;
                    missing_rankprog = false;
                }

                if (missing_engineer) {
                    spdlog::warn("Engineer entry missing 'Engineer'");
                    return false;
                }
                if (missing_engineerid) {
                    spdlog::warn("Engineer entry missing 'EngineerID'");
                    return false;
                }
                if (missing_progress) {
                    spdlog::warn("Engineer entry missing 'Progress'");
                    return false;
                }
                if (missing_rank) {
                    spdlog::warn("Engineer entry missing 'Rank'");
                    return false;
                }
                if (missing_rankprog) {
                    spdlog::warn("Engineer entry missing 'RankProgress'");
                    return false;
                }
            }
        }

        // ---------- Progress version (single engineer) ----------
        if (progress_present) {
            bool invited_or_known =
                (e.progress == std::optional<std::string>("Invited") ||
                 e.progress == std::optional<std::string>("Known"));

            bool missing_engineer   = !e.engineer.has_value();
            bool missing_engineerid = !e.engineer_id.has_value();
            bool missing_rank       = !e.rank.has_value();
            bool missing_rankprog   = !e.rank_progress.has_value();

            if (invited_or_known) {
                missing_rank = false;
                missing_rankprog = false;
            }

            if (missing_engineer) {
                spdlog::warn("Progress event missing 'Engineer'");
                return false;
            }
            if (missing_engineerid) {
                spdlog::warn("Progress event missing 'EngineerID'");
                return false;
            }
            if (missing_rank) {
                spdlog::warn("Progress event missing 'Rank'");
                return false;
            }
            if (missing_rankprog) {
                spdlog::warn("Progress event missing 'RankProgress'");
                return false;
            }
        }
        return true;
    }

    std::string iso8601_now() {
        using namespace std::chrono;

        auto now   = system_clock::now();
        auto tt    = system_clock::to_time_t(now);
        auto tm    = *gmtime(&tt);  // UTC

        std::ostringstream out;
        out << std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
        return out.str();
    }

    reader::reader(const std::string& journal_dir) : journal_dir(journal_dir), loghandle(),
                                                     running_process(journal_dir),
                                                     cargo_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }),
                                                     backpack_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }),
                                                     market_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }),
                                                     shipyard_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }),
                                                     navroute_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }),
                                                     outfitting_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }),
                                                     fcmaterials_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }),
                                                     moduleinfo_event(5s, [this](event ev) -> event {
                                                         return this->on_file(std::move(ev));
                                                     }), queue(queue_type(32)) {}

    template<class T>
    std::vector<T> reader::coalesce(const std::vector<T> &input) {
        auto cleaned = std::vector<T>();
        for (auto item : input) {
            // Find existing item in cleaned that matches canonically
            auto it = std::ranges::find_if(cleaned,
            [&](const T& x) {
                 return canonicalise(x.name) == canonicalise(item.name);
            });

            if (it == cleaned.end()) {
                // Not found → add a copy
                cleaned.push_back(item);
            } else {
                // Found → update count
                it->count += item.count;
            }
        }
        return cleaned;
    }

    event reader::on_file(event entry) {
        if (const auto event = entry.get_if<cargo>()) {
            if (event->inventory.has_value()) {
                auto cleaned = coalesce(event->inventory.value());
                for (auto& item : cleaned) {
                    state.cargo[item.name] = item.count;
                }
                event->inventory = std::move(cleaned);
                entry.serialize();
            }
        } else if (const auto event = entry.get_if<backpack>()) {
            state.backpack_json = entry.json();
            auto cleaned_components = coalesce(event->components.value());
            for (auto& item : cleaned_components) {
                state.backpack.component[item.name] = item.count;
            }
            auto cleaned_consumables = coalesce(event->consumables.value());
            for (auto& item : cleaned_consumables) {
                state.backpack.component[item.name] = item.count;
            }
            auto cleaned_items = coalesce(event->items.value());
            for (auto& item : cleaned_items) {
                state.backpack.item[item.name] = item.count;
            }
            auto cleaned_cargo = coalesce(event->data.value());
            for (auto& item : cleaned_cargo) {
                state.backpack.item[item.name] = item.count;
            }
        }
        return entry;
    }

    std::string reader::newest_journal(const std::string& journal_dir) {
        std::vector<fs::path> files;

        try {
            for (const auto& entry : fs::directory_iterator(journal_dir)) {
                const auto& name = entry.path().filename().string();
                if (RE2::FullMatch(name, RE_LOGFILE)) {
                    files.push_back(entry.path());
                }
            }
        }
        catch (const std::exception& e) {
            return {};
        }

        if (files.empty()) {
            return {};
        }

        // Lexicographically greatest path (same as Python's max(files))
        auto latest = *std::ranges::max_element(files);

        return latest.filename().string();
    }

    void reader::replay_file() {
        if(this->init) { return; }
        if(!fs::is_directory(journal_dir)) {
            return;
        }
        logfile = this->newest_journal(this->journal_dir);


        if(!this->logfile.empty()) {
            spdlog::debug("Replaying journal file {}", logfile);
            this->loghandle = journal_file(fs::path(journal_dir) / this->logfile);
            this->replay = true;
            std::string line;
            for (;;) {
                auto line = loghandle.readline();
                if (line.has_value()) {
                    this->parse_entry(line.value());
                } else {
                    break;
                }
            }

        }
        this->replay = false;

        spdlog::debug("finished journal file {}", logfile);

        game_was_running = running_process.running();
        if (live) {
            if (game_was_running) {
                spdlog::debug("game was/is running synthesizing StartUp event");
                auto entry = synthesize_startup_event();
                this->put_event(std::move(entry));
            } else {
                live = false;

                this->put_event(std::move(event()));
            }
        }
        this->init = true;
    }

    void reader::handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& file, efsw::Action action, std::string old) {
        using namespace efsw;

        this->replay_file();
        spdlog::info("event: {} {}", (int)action, file);
        if(action == Action::Add && RE2::FullMatch(file, RE_LOGFILE)) {
            if(file != logfile) {
                if(loghandle.is_open()) {
                    loghandle.close();
                }
                loghandle = journal_file(fs::path(journal_dir) / file);
            }
        }
        if(action == Action::Modified && file == logfile) {
            for (;;) {
                auto line = loghandle.readline();
                if (line.has_value()) {
                    auto entry = this->parse_entry(line.value());
                    if (entry) {
                        this->put_event(std::move(entry.value()));
                    }
                } else {
                    break;
                }
            }
        } else if (action == Action::Modified) {
            try {
                if (file == "Cargo.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e = cargo_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                } else if (file == "Backpack.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e = backpack_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                } else if (file == "Market.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e = market_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                } else if (file == "Shipyard.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e = shipyard_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                } else if (file == "NavRoute.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e =navroute_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                } else if (file == "Outfitting.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e = outfitting_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                } else if (file == "FCMaterials.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e = fcmaterials_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                } else if (file == "ModulesInfo.json") {
                    auto [event, timestamp] = from_file(file);
                    auto e = moduleinfo_event.file_arrived(std::move(event), timestamp);
                    if (e.has_value()) {
                        this->put_event(std::move(e.value()));
                    }
                }
            } catch (json::parse_error& e) {
                //ignore
            }
        }
        if (game_was_running && !running_process.running()) {
            auto ts = iso8601_now();
            json js;
            js = json::object();
            js["timestamp"] = ts;
            js["event"] = "ShutDown";
            shutdown ev = {
                "ShutDown",
                ts,
            };
            put_event(std::move(event(ev, js)));
        }
    }
    
    event reader::synthesize_startup_event() {
        startup ev = {
            .timestamp = iso8601_now(),
            .event = "StartUp",
            .star_system = state.system_name.value_or(""),
            .star_pos = state.star_pos,
            .system_address = state.system_address.value_or(0),
            .system_population = state.system_population.value_or(0),
            .body = state.body,
            .body_id = state.body_id,
            .body_type = state.body_type,
            .docked = state.is_docked,
            .market_id = state.market_id,
            .station_name = state.station_name,
            .station_type = state.station_type,
        };
        json js;
        to_json(js, ev);
        return {std::move(ev), std::move(js)};
    }

    std::pair<event, reader::timestamp> reader::from_file(const std::string &filename) {
        const auto path = fs::path(journal_dir) / filename;


        std::ifstream f(path);
        if (!f.is_open()) {
            throw std::runtime_error("Cannot open: " + path.string());
        }
        json json;
        try {
            json = json::parse(f);
        } catch (json::parse_error& e) {
            spdlog::error("error parsing: {}: {}", path.string(), e.what());
            throw;
        }

        if (!json.contains("timestamp") || !json.contains("event")) {
            throw std::runtime_error("Missing timestamp or event");
        }

        auto entry = this->events.parse_event(json);
        auto timestamp = parse_iso8601(json["timestamp"]);
        return {std::move(entry), timestamp};
    }

    void reader::put_event(event event) {
        if (event) {
            queue.raw().emplace(state, std::move(event));
        }
    }

    reader::timestamp reader::parse_iso8601(const std::string &s) {
        std::istringstream in{s};
        std::chrono::sys_time<std::chrono::milliseconds> tp;
#ifdef __APPLE__
        in >> date::parse("%FT%TZ", tp);
#else
        in >> std::chrono::parse("%FT%TZ", tp);
#endif
        if (in.fail())
        {
            in.clear();
            in.exceptions(std::ios::failbit);
            in.str(s);
#ifdef __APPLE__
            in >> date::parse("%FT%T%Ez", tp);
#else
            in >> std::chrono::parse("%FT%T%Ez", tp);
#endif
        }
        return tp;
    }

    std::optional<event> reader::parse_entry(const std::string& line) {
        json json;
        try {
            json = json::parse(line);
        } catch (json::parse_error& e) {
            spdlog::error("error parsing: {}: {}", line, e.what());
            return std::nullopt;
        }

        if (!json.contains("timestamp") || !json.contains("event")) {
            throw std::runtime_error("Missing timestamp or event");
        }

        auto entry = this->events.parse_event(json);
        if(entry.is<fileheader>()) {
            live = false;
            cmdr = "";
            mode = "";
            group = "";
            station_services.clear();
            started = timestamp::min();

            state = {};
            this->populate_version_info(entry, false);
        } else if(const auto event = entry.get_if<commander>()) {
            live = true;
            cmdr = event->name;
            state.fid = event->fid;
        } else if(const auto event = entry.get_if<load_game>()) {
            this->populate_version_info(entry, true);

            this->cmdr = event->commander;
            if ((!event->ship.has_value() && !event->game_mode.has_value()) || event->game_mode.value_or("") == "cqc") {
                this->mode = "CQC";
            } else {
                this->mode = event->game_mode.value();
            }

            this->group = event->group.value_or("");

            state.system_address   = std::nullopt;
            state.system_name      = std::nullopt;
            state.system_population= std::nullopt;
            state.star_pos.clear();
            state.body             = std::nullopt;
            state.body_id          = std::nullopt;
            state.body_type        = std::nullopt;
            state.station_name     = std::nullopt;
            state.market_id        = std::nullopt;
            state.station_type     = std::nullopt;

            this->station_services.clear();

            this->started = parse_iso8601(event->timestamp);

            state.captain   = std::nullopt;
            state.credits   = event->credits;
            state.fid       = event->fid;       // optional
            state.horizons  = event->horizons;
            state.odyssey   = event->odyssey.value_or(false);
            state.loan      = event->loan;

            // Statistics reset
            state.statistics = {};  // empty struct/map

            state.role       = std::nullopt;
            state.taxi       = false;
            state.dropship   = false;

            state.on_foot = (event->ship.has_value() && RE2::PartialMatch(event->ship.value(), RE_SHIP_ONFOOT));
        } else if (const auto event = entry.get_if<new_commander>()) {
            cmdr = event->name;
            group = "";
        } else if (const auto event = entry.get_if<set_user_ship_name>()) {
            state.ship_id = event->ship_id;
            state.ship_ident = event->user_ship_id;
            state.ship_name = event->user_ship_name;

            state.ship_type = canonicalise(event->ship);
        } else if (const auto event = entry.get_if<shipyard_buy>()) {
            state.ship_id      = std::nullopt;
            state.ship_ident   = std::nullopt;
            state.ship_name    = std::nullopt;
            state.ship_type    = canonicalise(event->ship_type);

            state.hull_value    = std::nullopt;
            state.modules_value = std::nullopt;
            state.rebuy         = std::nullopt;
            state.modules.clear();

            state.credits -= event->ship_price;
        } else if (const auto event = entry.get_if<shipyard_swap>()) {
            state.ship_id      = event->ship_id;     // mandatory
            state.ship_ident   = std::nullopt;
            state.ship_name    = std::nullopt;
            state.ship_type    = canonicalise(event->ship_type);

            state.hull_value    = std::nullopt;
            state.modules_value = std::nullopt;
            state.rebuy         = std::nullopt;
            state.modules.clear();
        } else if (const auto event = entry.get_if<carrier_stats>()) {
            carrier_ids.emplace(event->carrier_id, event->callsign);
        } else if (auto event = entry.get_if<carrier_jump_request>()) {
            event->callsign = get_callsign(event->carrier_id);
            entry.serialize();
        } else if (auto event = entry.get_if<carrier_jump_cancelled>()) {
            event->callsign = get_callsign(event->carrier_id);
            entry.serialize();
        } else if (auto event = entry.get_if<carrier_jump>()) {
            std::string one, two;
            if (RE2::FullMatch(event->station_name, RE_FC_JUMP_NAME,RE2::Arg(&one), RE2::Arg(&two))) {
                event->callsign = fmt::format("{}-{}", one, two);
                entry.serialize();
            }
        } else if (const auto event = entry.get_if<loadout>()) {
            if (!canonicalise(event->ship).contains("fighter") && !canonicalise(event->ship).contains("buggy")) {
                state.ship_id = event->ship_id;
                state.ship_ident = event->ship;

                if (state.ship_name.has_value() && !state.ship_name->empty() && state.ship_name != " ") {
                    state.ship_name = event->ship_name;
                }

                state.ship_type = canonicalise(event->ship);
                state.hull_value    = event->hull_value;
                state.modules_value = event->modules_value;
                state.unladen_mass = event->unladen_mass;
                state.cargo_capacity = event->cargo_capacity;
                state.max_jump_range = event->max_jump_range;
                state.fuel_capacity = {
                    event->fuel_capacity.main,
                    event->fuel_capacity.reserve
                };
                state.rebuy = event->rebuy;

                event->modules.clear();
                for (auto module: event->modules) {
                    hue::module mod = hue::module(module);
                    bool is_hardpoint = module.slot.contains("Hardpoint") && !module.slot.starts_with("TinyHardpoint");

                    bool ammo_clip_is_one = module.ammo_in_clip == 1 && module.ammo_in_hopper == 1;

                    if (is_hardpoint && ammo_clip_is_one) {
                        mod.ammo_in_clip = std::nullopt;
                        mod.ammo_in_hopper = std::nullopt;
                    }
                    state.modules.emplace(module.slot, mod);
                }

                nlohmann::json initial = {
                    {"header", {
                                        {"appName", "hugh"},
                                        {"appVersion", "0.1.0"}
                    }}
                };

                nlohmann::json data = json::object();
                for (auto module : event->modules) {
                    if (module.slot == "FuelTank") {
                        auto item = module.item;
                        std::size_t pos = item.find("size");
                        if (pos != std::string::npos) {
                            std::string after_size = item.substr(pos + 4); // length("size") = 4

                            auto underscore = after_size.find("_");
                            if (underscore != std::string::npos) {
                                std::string size_num = after_size.substr(0, underscore);
                                int exponent = std::stoi(size_num);

                                int cap = 1 << exponent;  // 2 ** exponent, exactly as Python
                                std::string ship_name = event->ship_name;
                                std::string ship_key = ship_name_map.at(ship_name);

                                nlohmann::json fuel = {
                                    {
                                        {"Main", cap},
                                        {"Reserve", ship_data.at(ship_key).reserveFuelCapacity}
                                    }};

                                data["FuelCapacity"] = fuel;
                            }
                        }
                    }
                }
                data["Ship"]          = event->ship;
                data["ShipName"]      = event->ship_name;
                data["ShipIdent"]     = event->ship_ident;
                data["HullValue"]     = event->hull_value;
                data["ModulesValue"]  = event->modules_value;
                data["Rebuy"]         = event->rebuy;
                data["MaxJumpRange"]  = event->max_jump_range;
                data["UnladenMass"]   = event->unladen_mass;
                data["CargoCapacity"] = event->cargo_capacity;
                data["Modules"]       = event->modules;

                initial["schema"] = data;

                std::string output = initial.dump(4);
                slef = "[" + output + "]";
            }

        } else if (const auto event = entry.get_if<module_buy>()) {
            state.modules[event->slot] = hue::module(
                std::nullopt,
                std::nullopt,
                std::nullopt,
                1.0,
                canonicalise(event->buy_item),
                true,
                1,
                event->slot,
                event->buy_price
                );

            state.credits -= event->buy_price;
        } else if (const auto event = entry.get_if<module_sell>()) {
            state.modules.erase(event->slot);
            state.credits += event->sell_price;
        } else if (const auto event = entry.get_if<module_sell_remote>()) {
            state.credits += event->sell_price;
        } else if (const auto event = entry.get_if<module_store>()) {
            state.modules.erase(event->slot);
            state.credits -= event->cost.value_or(0);
        } else if (const auto event = entry.get_if<module_swap>()) {
            auto& modules = state.modules;
            auto from_slot = event->from_slot;
            auto to_slot   = event->to_slot;

            auto it_from = modules.find(from_slot);
            if (it_from != modules.end()) {
                auto it_to = modules.find(to_slot);

                if (it_to != modules.end()) {
                    std::swap(it_from->second, it_to->second);
                } else {
                    modules[to_slot] = std::move(it_from->second);
                    modules.erase(it_from);
                }
            }
        } else if (const auto event = entry.get_if<undocked>()) {
            state.station_name = std::nullopt;
            state.market_id = std::nullopt;
            state.station_type = std::nullopt;
            station_services.clear();
            state.is_docked = false;
        } else if (const auto event = entry.get_if<embark>()) {
            state.station_name = std::nullopt;
            state.market_id = std::nullopt;
            if (event->on_station) {
                state.station_name = event->station_name;
                state.market_id = event->market_id;
            }
            state.on_foot = false;
            state.taxi = event->taxi;

            state.backpack.data.clear();
            state.backpack.component.clear();
            state.backpack.item.clear();
            state.backpack.consumable.clear();
        } else if (const auto event = entry.get_if<disembark>()) {
            if (event->on_station == false) {
                state.station_name = event->station_name;
            } else {
                state.station_name = std::nullopt;
            }

            state.on_foot = true;
            if (!state.taxi && state.taxi != event->taxi) {
                //warning: disembarked from a taxi but we didn't know!
            }

            state.taxi = false;
            state.dropship = false;
        } else if (entry.is<dropship_deploy>()) {
            state.on_foot = true;
            state.taxi = false;
            state.dropship = false;
        } else if (const auto event = entry.get_if<supercruise_exit>()) {
            if (event->body_type == "Station") {
                state.body = std::nullopt;
                state.body_id = std::nullopt;
            }
        } else if (const auto event = entry.get_if<docked>()) {
            state.is_docked = true;
            state.station_name = event->station_name;
            state.market_id = event->market_id;
            state.station_type = event->station_type;
            station_services = event->station_services;
        } else if (entry.is<location>() || entry.is<fsd_jump>() || entry.is<carrier_jump>()) {
            /*
                Notes on tracking of a player's location.

                Body
                ---
                There are some caveats about tracking Body name, ID and type,
                mostly due to close-orbiting binary planets/moons.

                Presence on or near a Body is indicated in several scenarios:

                1. When the player logs in.
                2. When the player's location changes due to being docked
                  on a Fleet Carrier when it jumps.
                3. When the player flies within Orbital Cruise range of a
                  Body.

                For the first case this will always be a 'Location' event.
                If landed on a Body, or docked at a surface port then this
                will be indicated.  However, if docked at an orbital station
                the 'Body' is the name of that station, with 'BodyType' having
                'Station' as its value.

                In the second case although it *should* be a 'CarrierJump'
                event, for a while now it's actually been a 'Location' event.
                This should follow the same rules as being docked at an
                orbital station.

                For the last case there are some caveats to do with close
                orbiting binary bodies:

                1. 'ApproachBody' indicates presence near the Body in question.
                2. 'LeaveBody' indicates the player is no longer considered
                  to be near the Body.  This is specifically when no longer
                  in Orbital Cruise around the Body such that the HUD for that
                  has been switched out for the normal SuperCruise one.
                3. 'SupercruiseExit' does not indicate any change of presence
                  near a Body.
                4. 'SupercruiseEntry' *also* **DOES NOT** indicate that the
                  player is no longer near the Body.  They can easily utilise
                  Orbital Cruise to rapidly travel around the Body and then
                  land on it again **without a fresh 'ApproachBody'** event.

                  The only way to check for this is to utilise the Body (name)
                  present in `Status.json` schema, as this *will* correctly
                  reflect the second Body.
            */
            if (const auto e = entry.get_if<location>()) {
                // Body fields
                state.body      = e->body;
                state.body_id   = e->body_id;
                state.body_type = e->body_type;

                // Docking
                state.is_docked = e->docked;
                // System fields
                if (e->star_pos.size() == 3) {
                    state.star_pos = e->star_pos;
                } else {
                    //log_warning("location event missing StarPos");
                }

                state.system_address    = e->system_address;
                state.system_population = e->population;

                if (e->star_system == "ProvingGround")
                    state.system_name = "CQC";
                else
                    state.system_name = e->star_system;

                // Station fields
                state.station_name = e->station_name;

                // body_type == Station overrides station_name
                if (e->body_type == "Station") {
                    state.station_name = e->body;
                }

                state.market_id        = e->market_id;
                state.station_type     = e->station_type;
                station_services = e->station_services.value_or(std::vector<std::string>());

                // Taxi / Dropship
                state.taxi = e->taxi.value_or(false);
                if (!state.taxi || state.taxi == false)
                    state.dropship = false;
            }
            if (const auto e = entry.get_if<carrier_jump>()) {
                // Body fields
                state.body      = e->body;
                state.body_id   = e->body_id;
                state.body_type = e->body_type;

                // System fields
                if (e->star_pos.size() == 3) {
                    state.star_pos = e->star_pos;
                } else {
                    //log_warning("location event missing StarPos");
                }

                state.system_address    = e->system_address;
                state.system_population = e->population;

                if (e->star_system == "ProvingGround")
                    state.system_name = "CQC";
                else
                    state.system_name = e->star_system;

                // Station (none — same as Python)
                state.station_name     = std::nullopt;
                state.market_id        = std::nullopt;
                state.station_type     = std::nullopt;
                station_services.clear();

                // Taxi / Dropship
                state.taxi = e->taxi.value_or(false);
                if (!state.taxi || state.taxi == false)
                    state.dropship = false;
            }
            if (const auto e = entry.get_if<fsd_jump>()) {
                // Body cleared
                state.body      = std::nullopt;
                state.body_id   = std::nullopt;
                state.body_type = std::nullopt;

                // System fields
                if (e->star_pos.size() == 3) {
                    state.star_pos = e->star_pos;
                } else {
                    //log_warning("location event missing StarPos");
                }

                state.system_address    = e->system_address;
                state.system_population = e->population;

                if (e->star_system == "ProvingGround")
                    state.system_name = "CQC";
                else
                    state.system_name = e->star_system;

                // Station reset
                state.station_name     = std::nullopt;
                state.market_id        = std::nullopt;
                state.station_type     = std::nullopt;
                station_services.clear();

                // Taxi / Dropship
                state.taxi = e->taxi.value_or(false);
                if (!state.taxi || state.taxi == false)
                    state.dropship = false;
            }
        } else if (const auto event = entry.get_if<approach_body>()) {
            state.body = event->body;
            state.body_id = event->body_id;
            state.body_type = "Planet";
        } else if (const auto event = entry.get_if<leave_body>()) {
            state.body = std::nullopt;
            state.body_id = std::nullopt;
            state.body_type = std::nullopt;
        } else if (const auto event = entry.get_if<supercruise_entry>()) {
            if (state.body_type == "Station") {
                state.body = std::nullopt;
                state.body_id = std::nullopt;
                state.body_type = std::nullopt;
            }

            state.station_name = std::nullopt;
            state.market_id    = std::nullopt;
            state.station_type = std::nullopt;
            station_services.clear();
        } else if (const auto event = entry.get_if<music>()) {
            if (event->music_track == "MainMenu") {
                state.body = std::nullopt;
                state.body_id = std::nullopt;
                state.body_type = std::nullopt;
            }
        } else if (entry.is<rank>() || entry.is<promotion>()) {
            const auto& json = entry.json();
            for (const auto& [key, value] : json.items()) {
                if (key == "event" || key == "timestamp")
                    continue;

                state.rank.emplace(key, std::tuple{ value.get<int>(), 0 });
            }
        } else if (entry.is<progress>()) {
            const auto& json = entry.json();
            for (const auto& [key, value] : json.items()) {
                auto it = state.rank.find(key);
                if (it == state.rank.end())
                    continue; // key not tracked in rank

                auto& [score, progress] = it->second;

                int v = value.get<int>();   // safe typed conversion
                progress = std::min(v, 100);
            }
        } else if (const auto event = entry.get_if<engineer_progress>()) {
            if (event_valid_engineerprogress(*event)) {
                if (event->engineers.has_value()) {
                    state.engineers.clear();
                    for (const auto& e : event->engineers.value()) {
                        // Has Rank?
                        if (e.rank.has_value()) {
                            int rank = *e.rank;
                            int rank_prog = e.rank_progress.value_or(0);
                            state.engineers.emplace(e.engineer, std::make_pair(rank, rank_prog));
                        } else {
                            // No rank → store the Progress string
                            state.engineers.emplace(e.engineer, e.progress);
                        }
                    }
                } else {
                    if (event->engineer.has_value()) {
                        // Has Rank?
                        if (event->rank.has_value()) {
                            int rank = event->rank.value();
                            int rank_prog = event->rank_progress.value_or(0);
                            state.engineers.emplace(event->engineer.value(), std::make_pair(rank, rank_prog));
                        } else {
                            state.engineers.emplace(event->engineer.value(), event->progress.value_or(""));
                        }
                    }
                }
            }
        } else if (const auto event = entry.get_if<cargo>()) {
            if (event->vessel == "Ship") {
                return cargo_event.journal_arrived(std::move(entry), parse_iso8601(event->timestamp));
            }
        } else if (const auto event = entry.get_if<cargo_transfer>()) {
            for (auto e : event->transfers) {
                auto name = canonicalise(e.type);
                if (e.direction == "toship") {
                    state.cargo[name] += e.count;
                } else {
                    state.cargo[name] -= e.count;
                }
            }
        } else if (const auto event = entry.get_if<ship_locker>()) {
            //TODO: fill this in
        } else if (entry.is<backpack>() || entry.is<resupply>()) {
            return backpack_event.journal_arrived(std::move(entry), parse_iso8601(entry.json()["timestamp"]));
        } else if (const auto event = entry.get_if<backpack_change>()) {
            if (event->added.has_value()) {
                for (auto entry : event->added.value()) {
                    auto cat = category(entry.type);
                    auto name = canonicalise(entry.name);

                    if (cat == "Data") {
                        state.backpack.data[name] += entry.count;
                    } else if (cat == "Component") {
                        state.backpack.component[name] += entry.count;
                    } else if (cat == "Item") {
                        state.backpack.item[name] += entry.count;
                    } else if (cat == "Consumable") {
                        state.backpack.consumable[name] += entry.count;
                    }
                }
            } else if (event->removed.has_value()) {
                for (auto entry : event->removed.value()) {
                    auto cat = category(entry.type);
                    auto name = canonicalise(entry.name);

                    if (cat == "Data") {
                        state.backpack.data[name] -= entry.count;
                    } else if (cat == "Component") {
                        state.backpack.component[name] -= entry.count;
                    } else if (cat == "Item") {
                        state.backpack.item[name] -= entry.count;
                    } else if (cat == "Consumable") {
                        state.backpack.consumable[name] -= entry.count;
                    }
                }
            }
        } else if (const auto event = entry.get_if<buy_micro_resources>()) {
            state.credits -= event->price;
        } else if (const auto event = entry.get_if<sell_micro_resources>()) {
            state.credits += event->price;
        } else if (const auto event = entry.get_if<book_dropship>()) {
            state.credits -= event->cost;
            state.dropship = true;
        } else if (const auto event = entry.get_if<book_taxi>()) {
            state.credits -= event->cost;
        } else if (const auto event = entry.get_if<cancel_dropship>()) {
            state.credits += event->refund;
            state.dropship = false;
            state.taxi = false;
        } else if (const auto event = entry.get_if<cancel_taxi>()) {
            state.credits += event->refund;
            state.taxi = false;
        } else if (entry.is<market>() && !replay) {
            return market_event.journal_arrived(std::move(entry), parse_iso8601(entry.json()["timestamp"]));
        }else if (entry.is<shipyard>() && !replay) {
            return shipyard_event.journal_arrived(std::move(entry), parse_iso8601(entry.json()["timestamp"]));
        }else if (entry.is<nav_route>() && !replay) {
            return navroute_event.journal_arrived(std::move(entry), parse_iso8601(entry.json()["timestamp"]));
        }else if (entry.is<outfitting>() && !replay) {
            return outfitting_event.journal_arrived(std::move(entry), parse_iso8601(entry.json()["timestamp"]));
        }else if (entry.is<fc_materials>() && !replay) {
            return fcmaterials_event.journal_arrived(std::move(entry), parse_iso8601(entry.json()["timestamp"]));
        }else if (entry.is<module_info>() && !replay) {
            return moduleinfo_event.journal_arrived(std::move(entry), parse_iso8601(entry.json()["timestamp"]));
        } else if (const auto event = entry.get_if<collect_cargo>()) {
            auto commodity = canonicalise(event->type);
            state.cargo[commodity] += 1;
        } else if (const auto event = entry.get_if<market_buy>()) {
            auto commodity = canonicalise(event->type);
            state.cargo[commodity] += event->count;
            state.credits -= event->total_cost;
        } else if (const auto event = entry.get_if<buy_drones>()) {
            auto commodity = canonicalise(event->type);
            state.cargo[commodity] += event->count;
            state.credits -= event->total_cost;
        } else if (const auto event = entry.get_if<mining_refined>()) {
            auto commodity = canonicalise(event->type);
            state.cargo[commodity] += 1;
        } else if (const auto event = entry.get_if<eject_cargo>()) {
            auto commodity = canonicalise(event->type);
            state.cargo[commodity] -= event->count;
            if (state.cargo[commodity] <= 0) {
                state.cargo.erase(commodity);
            }
        }else if (const auto event = entry.get_if<market_sell>()) {
            auto commodity = canonicalise(event->type);
            state.cargo[commodity] -= event->count;
            if (state.cargo[commodity] <= 0) {
                state.cargo.erase(commodity);
            }
            state.credits += event->total_sale;
        } else if (const auto event = entry.get_if<sell_drones>()) {
            auto commodity = canonicalise(event->type);
            state.cargo[commodity] -= event->count;
            if (state.cargo[commodity] <= 0) {
                state.cargo.erase(commodity);
            }
            state.credits += event->total_sale;
        } else if (const auto event = entry.get_if<search_and_rescue>()) {
            auto commodity = canonicalise(event->name);
            state.cargo[commodity] -= event->count;
            if (state.cargo[commodity] <= 0) {
                state.cargo.erase(commodity);
            }
        } else if (const auto event = entry.get_if<materials>()) {
            for (auto & i : event->raw) {
                state.raw[canonicalise(i.name)] = i.count;
            }
            for (auto & i : event->manufactured) {
                state.manufactured[canonicalise(i.name)] = i.count;
            }
            for (auto & i : event->encoded) {
                state.encoded[canonicalise(i.name)] = i.count;
            }
        } else if (const auto event = entry.get_if<material_collected>()) {
            auto commodity = canonicalise(event->name);
            if (event->category == "Raw") {
                state.raw[commodity] += event->count;
            } else if (event->category == "Manufactured") {
                state.manufactured[commodity] += event->count;
            } else if (event->category == "Encoded") {
                state.encoded[commodity] += event->count;
            }
        } else if (const auto event = entry.get_if<material_discarded>()) {
            auto commodity = canonicalise(event->name);
            if (event->category == "Raw") {
                state.raw[commodity] -= event->count;
            } else if (event->category == "Manufactured") {
                state.manufactured[commodity] -= event->count;
            } else if (event->category == "Encoded") {
                state.encoded[commodity] -= event->count;
            }
        }else if (const auto event = entry.get_if<scientific_research>()) {
            auto commodity = canonicalise(event->name);
            if (event->category == "Raw") {
                state.raw[commodity] -= event->count;
            } else if (event->category == "Manufactured") {
                state.manufactured[commodity] -= event->count;
            } else if (event->category == "Encoded") {
                state.encoded[commodity] -= event->count;
            }
        } else if (const auto event = entry.get_if<synthesis>()) {
            for (auto &i: event->materials) {
                auto commodity = canonicalise(i.name);
                auto remove_from = [&](auto& map) {
                    if (auto it = map.find(commodity); it != map.end()) {
                        it->second -= i.count;
                        if (it->second <= 0) {
                            map.erase(it);
                        }
                    }
                };

                remove_from(state.raw);
                remove_from(state.manufactured);
                remove_from(state.encoded);
            }
        } else if (const auto event = entry.get_if<material_trade>()) {
            auto cat = category(event->paid.category);
            if (cat == "Raw") {
                state.raw[event->paid.material] -= event->paid.quantity;
                if (state.raw[event->paid.material] <= 0) {
                    state.raw.erase(event->paid.material);
                }
            } else if (cat == "Encoded") {
                state.encoded[event->paid.material] -= event->paid.quantity;
                if (state.encoded[event->paid.material] <= 0) {
                    state.encoded.erase(event->paid.material);
                }
            } else if (cat == "Manufactured") {
                state.manufactured[event->paid.material] -= event->paid.quantity;
                if (state.manufactured[event->paid.material] <= 0) {
                    state.manufactured.erase(event->paid.material);
                }
            }
            cat = category(event->received.category);
            if (cat == "Raw") {
                state.raw[event->received.material] += event->received.quantity;
            } else if (cat == "Encoded") {
                state.encoded[event->received.material] += event->received.quantity;
            } else if (cat == "Manufactured") {
                state.manufactured[event->received.material] += event->received.quantity;
            }
        } else if (const auto event = entry.get_if<engineer_craft>()) {
            for (auto &i: event->ingredients) {
                auto commodity = canonicalise(i.name);
                auto remove_from = [&](auto& map) {
                    if (auto it = map.find(commodity); it != map.end()) {
                        it->second -= i.count;
                        if (it->second <= 0) {
                            map.erase(it);
                        }
                    }
                };

                remove_from(state.raw);
                remove_from(state.manufactured);
                remove_from(state.encoded);
            }

            auto module = state.modules[event->slot];
            if (module.item != canonicalise(event->engineer_craft_module)) {
                throw std::runtime_error("module is not the crafted module");
            }
			std::vector<module_modifier> mods;
            for (auto& m : event->modifiers) {
                mods.push_back(module_modifier{
                    m.label,
                    m.less_is_good,
                    m.original_value,
                    m.value,
                    m.value_str,
                    m.value_str_localised
				});
            }
            module.engineering = hue::module_engineering{
                .blueprint_id = event->blueprint_id,
                .blueprint_name = event->blueprint_name,
                .engineer = event->engineer,
                .engineer_id = event->engineer_id,
                .experimental_effect = event->experimental_effect,
                .experimental_effect_localised = event->experimental_effect_localised,
                .level = event->level,
                .modifiers = mods,
                .quality = event->quality,
            };
        }  else if (const auto event = entry.get_if<mission_completed>()) {
            // Add base credit reward
            state.credits += event->reward.value_or(0);

            if (event->commodity_reward.has_value()) {
                for (const auto &r : event->commodity_reward.value()) {
                    auto commodity = canonicalise(r.name);
                    state.cargo[commodity] += r.count;
                }
            }

            if (event->materials_reward.has_value()) {
                for (const auto &r : event->materials_reward.value()) {
                    auto cat = category(r.category); // your existing category() function
                    auto material = canonicalise(r.name);

                    // ED 3.0 compatibility fix
                    if (cat == "Elements")
                        cat = "Raw";

                    if (cat == "Raw") {
                        state.raw[material] += r.count;
                    } else if (cat == "Encoded") {
                        state.encoded[material] += r.count;
                    } else if (cat == "Manufactured") {
                        state.encoded[material] += r.count;
                    }
                }
            }
        } else if (const auto event = entry.get_if<engineer_contribution>()) {
            if (!event->commodity.has_value()) {
                auto c = canonicalise(event->commodity.value());
                if (auto it = state.cargo.find(c); it != state.cargo.end()) {
                    it->second -= event->quantity;
                    if (it->second <= 0) state.cargo.erase(it);
                }
            }

            if (!event->material.has_value()) {
                auto m = canonicalise(event->material.value());
                auto remove_from = [&](auto &map) {
                    if (auto it = map.find(m); it != map.end()) {
                        it->second -= event->quantity;
                        if (it->second <= 0) map.erase(it);
                    }
                };
                remove_from(state.raw);
                remove_from(state.manufactured);
                remove_from(state.encoded);
            }

        } else if (const auto event = entry.get_if<technology_broker>()) {
            for (const auto &i : event->commodities) {
                auto c = canonicalise(i.name);
                auto it = state.cargo.find(c);
                if (it != state.cargo.end()) {
                    it->second -= i.count;
                    if (it->second <= 0) state.cargo.erase(it);
                }
            }

            for (const auto &i : event->materials) {
                auto m = canonicalise(i.name);
                auto &map =
                    (i.category == "Raw") ? state.raw :
                    (i.category == "Manufactured") ? state.manufactured :
                    state.encoded;

                map[m] -= i.count;
                if (map[m] <= 0) map.erase(m);
            }

        } else if (const auto event = entry.get_if<join_a_crew>()) {
            state.captain = event->captain;
            state.role = "Idle";
            state.star_pos = {};
            state.system_name = {};
            state.system_address = {};
            state.system_population = {};
            state.body = {};
            state.body_id = {};
            state.body_type = {};
            state.station_name = {};
            state.market_id = {};
            state.station_type = {};
            station_services.clear();
            state.on_foot = false;

        } else if (const auto event = entry.get_if<change_crew_role>()) {
            state.role = event->role;

        } else if (const auto event = entry.get_if<quit_a_crew>()) {
            state.captain = {};
            state.role = {};
            state.system_name = {};
            state.system_address = {};
            state.system_population = {};
            state.star_pos = {};
            state.body = {};
            state.body_id = {};
            state.body_type = {};
            state.station_name = {};
            state.market_id = {};
            state.station_type = {};
            station_services.clear();

        } else if (const auto event = entry.get_if<friends>()) {
            if (event->status == "Online" || event->status == "Added")
                state.friends.insert(event->name);
            else
                state.friends.erase(event->name);

        } else if (const auto event = entry.get_if<sell_exploration_data>()) {
            state.credits += event->total_earnings;

        } else if (const auto event = entry.get_if<buy_exploration_data>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<buy_trade_data>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<buy_ammo>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<community_goal_reward>()) {
            state.credits += event->reward;

        } else if (const auto event = entry.get_if<crew_hire>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<fetch_remote_module>()) {
            state.credits -= event->transfer_cost;

        } else if (const auto event = entry.get_if<mission_abandoned>()) {
            // intentionally empty
        } else if (const auto event = entry.get_if<pay_bounties>()) {
            state.credits -= event->amount;

        } else if (const auto event = entry.get_if<redeem_voucher>()) {
            state.credits += event->amount;

        } else if (const auto event = entry.get_if<refuel_all>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<repair>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<restock_vehicle>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<sell_ship_on_rebuy>()) {
            state.credits += event->ship_price;

        } else if (const auto event = entry.get_if<shipyard_buy>()) {
            state.credits += event->ship_price;

        } else if (const auto event = entry.get_if<shipyard_transfer>()) {
            state.credits -= event->transfer_price;

        } else if (const auto event = entry.get_if<powerplay_fast_track>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<powerplay_salary>()) {
            state.credits += event->amount;

        } else if (const auto event = entry.get_if<squadron_created>()) {
            // empty
        } else if (const auto event = entry.get_if<carrier_buy>()) {
            state.credits -= event->price;

        } else if (const auto event = entry.get_if<carrier_bank_transfer>()) {
            state.credits = event->player_balance;
        } else if (const auto event = entry.get_if<carrier_decommission>()) {
            // empty
        } else if (const auto event = entry.get_if<npc_crew_paid_wage>()) {
            state.credits -= event->amount;

        } else if (const auto event = entry.get_if<resurrect>()) {
            state.credits -= event->cost;

        } else if (const auto event = entry.get_if<powerplay>()) {
            state.power_play.power = event->power;
            state.power_play.rank = event->rank;
            state.power_play.merits = event->merits;
            state.power_play.votes = event->votes;
            state.power_play.time_pledged = event->time_pledged;

        } else if (const auto event = entry.get_if<powerplay_merits>()) {
            state.power_play.merits = event->total_merits;

        } else if (const auto event = entry.get_if<powerplay_rank>()) {
            state.power_play.rank = event->rank;
        }

        return entry;
    }

    std::string reader::suit_sane_name(const std::string& in) {
        std::string name = in;

        // static const RE2 re_stage1(R"((?i)^\$([^_]+)_Class([0-9]+)_Name;$)");
        // static const RE2 re_stage2(R"((?i)^([^_]+)_class([0-9]+)$)");
        //
        // std::string type;
        // std::string cls;
        //
        // // Stage 1
        // if (RE2::FullMatch(name, re_stage1, &type, &cls)) {
        //     name = type;
        // }
        // // Stage 2
        // else if (RE2::FullMatch(name, re_stage2, &type, &cls)) {
        //     name = type;
        // }
        //
        // // Stage 3 — localisation lookup
        // auto it_lang = edmc_suit_symbol_localised.find(state.game_language);
        // if (it_lang != edmc_suit_symbol_localised.end()) {
        //     const auto& lang_map = it_lang->second;
        //     auto it = lang_map.find(std::to_lower(name));
        //     if (it != lang_map.end())
        //         name = it->second;
        // }
        //
        // // Final mapping removing " Suit"
        // if (auto it = edmc_suit_shortnames.find(name); it != edmc_suit_shortnames.end())
        //     name = it->second;

        return name;
    }

    std::tuple<int64_t, int64_t> reader::suit_loadout_store_from_event(event event) {
        auto json = event.json();
        int64_t suit_id = json["SuitID"].get<int64_t>();

        auto it = state.suits.find(suit_id);
        suit current;
        if (it == state.suits.end()) {
            auto suit_name = get_stack_optional<std::string>(json, "SuitName_Localised")
            .value_or(json["SuitName"].get<std::string>());
            auto edmc_name = suit_sane_name(suit_name);
            current = suit {
                .edmc_name = edmc_name,
                .loc_name = suit_name,
            };
        } else {
            current = it->second;
        }

        current.suit_id = suit_id;
        current.name = json["SuitName"].get<std::string>();
        current.mods = json["SuitMods"].get<std::vector<std::string>>();

        auto suitloadout_slotid = suit_loadout_id_from_loadout_id(json["LoadoutID"].get<int64_t>());
        suit_loadout loadout = suit_loadout {
            .loadout_slot_id =  suitloadout_slotid,
            .current_suit = current,
            .name = json["LoadoutName"].get<std::string>(),
        };
        state.suit_loadouts[suitloadout_slotid] = loadout;
        state.suits[suit_id] = current;
        return std::make_pair(suit_id, suitloadout_slotid);
    }

    int64_t reader::suit_loadout_id_from_loadout_id(int64_t loadout_id) {
        return loadout_id - 4293000000;
    }

    std::optional<std::string> reader::get_callsign(int64_t carrier_id) {
        if (const auto it = carrier_ids.find(carrier_id); it != carrier_ids.end())
            return it->second;
        return std::nullopt;
    }
    void reader::populate_version_info(event &event, bool suppress) {
        auto& json = event.json();
        try {
            this->state.game_language = json.at("language").get<std::string>();
            this->state.game_version  = json.at("gameversion").get<std::string>();
            this->state.game_build    = json.at("build").get<std::string>();

            this->version = this->state.game_version.value_or("");

            if (auto sv = coerce_semver(this->state.game_version.value()); sv.valid) {
                this->semver = sv;
            } else {
                this->semver = {};
            }

            // --- is_beta detection ---
            std::string lower = this->version;
            std::ranges::transform(lower, lower.begin(),
                                   [](unsigned char c){ return std::tolower(c); });

            this->is_beta = (lower.find("alpha") != std::string::npos) ||
                            (lower.find("beta")  != std::string::npos);

        } catch (const json::out_of_range&) {
            if (!suppress) throw;
            // else match Python behavior: fail silently
        }
    }

    std::string reader::category(std::string item) {
        if (item.empty()) {
            return "";
        }

        std::string out;
        if (RE2::FullMatch(item, RE_CATEGORY, &out)) {
            out[0] = std::toupper(out[0]);
            return out;
        }
        item[0] = std::toupper(item[0]);
        return item;
    }

    std::string reader::canonicalise(const std::string& item) {
        if (item.empty())
            return "";

        // lowercase
        std::string s = item;
        std::ranges::transform(s, s.begin(),
                               [](const unsigned char c){ return std::tolower(c); });

        // capture buffer
        std::string out;

        // Full match (Python's re.match matches from start)
        if (RE2::FullMatch(s, RE_CANONICALISE, &out))
            return out;

        // no match: return lowercase item
        return s;
    }

}