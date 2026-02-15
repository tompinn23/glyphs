//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_info data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct ship_module {
        std::string item;
        double power;
        std::optional<int64_t> priority;
        std::string slot;
    };

    /**
     * When written: when looking at the cockpit Right Hand Side modules info panel, if data has
     * changed. This also writes a ModulesInfo.json file alongside the journal, listing the
     * modules in the same order as displayed.
     */
    struct module_info {
        std::string event;
        /**
         * When written to ModulesInfo.json
         */
        std::optional<std::vector<ship_module>> modules;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, ship_module & x);
    void to_json(json & j, const ship_module & x);

    void from_json(const json & j, module_info & x);
    void to_json(json & j, const module_info & x);

    inline void from_json(const json & j, ship_module& x) {
        x.item = j.at("Item").get<std::string>();
        x.power = j.at("Power").get<double>();
        x.priority = get_stack_optional<int64_t>(j, "Priority");
        x.slot = j.at("Slot").get<std::string>();
    }

    inline void to_json(json & j, const ship_module & x) {
        j = json::object();
        j["Item"] = x.item;
        j["Power"] = x.power;
        j["Priority"] = x.priority;
        j["Slot"] = x.slot;
    }

    inline void from_json(const json & j, module_info& x) {
        x.event = j.at("event").get<std::string>();
        x.modules = get_stack_optional<std::vector<ship_module>>(j, "Modules");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const module_info & x) {
        j = json::object();
        j["event"] = x.event;
        j["Modules"] = x.modules;
        j["timestamp"] = x.timestamp;
    }
}


