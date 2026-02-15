//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     suit_loadout data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    /**
     * This event is logged when starting on-foot or when disembarking
     */
    struct suit_loadout {
        std::string event;
        int64_t loadout_id;
        std::string loadout_name;
        std::vector<common::suit_module_element> modules;
        int64_t suit_id;
        std::vector<std::string> suit_mods;
        std::string suit_name;
        std::optional<std::string> suit_name_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {


    void from_json(const json & j, suit_loadout & x);
    void to_json(json & j, const suit_loadout & x);


    inline void from_json(const json & j, suit_loadout& x) {
        x.event = j.at("event").get<std::string>();
        x.loadout_id = j.at("LoadoutID").get<int64_t>();
        x.loadout_name = j.at("LoadoutName").get<std::string>();
        x.modules = j.at("Modules").get<std::vector<common::suit_module_element>>();
        x.suit_id = j.at("SuitID").get<int64_t>();
        x.suit_mods = j.at("SuitMods").get<std::vector<std::string>>();
        x.suit_name = j.at("SuitName").get<std::string>();
        x.suit_name_localised = get_stack_optional<std::string>(j, "SuitName_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const suit_loadout & x) {
        j = json::object();
        j["event"] = x.event;
        j["LoadoutID"] = x.loadout_id;
        j["LoadoutName"] = x.loadout_name;
        j["Modules"] = x.modules;
        j["SuitID"] = x.suit_id;
        j["SuitMods"] = x.suit_mods;
        j["SuitName"] = x.suit_name;
        j["SuitName_Localised"] = x.suit_name_localised;
        j["timestamp"] = x.timestamp;
    }
}


