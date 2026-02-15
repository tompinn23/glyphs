//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     launch_fighter data = nlohmann::json::parse(jsonString);

#pragma once

#include "nlohmann/json.hpp"

namespace hue {
    using nlohmann::json;

    #ifndef NLOHMANN_UNTYPED_hue_HELPER
    #define NLOHMANN_UNTYPED_hue_HELPER
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    #endif

    /**
     * When written: when launching a fighter
     */
    struct launch_fighter {
        std::string event;
        int64_t id;
        std::string loadout;
        /**
         * Whether player is controlling the fighter from launch
         */
        bool player_controlled;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, launch_fighter & x);
    void to_json(json & j, const launch_fighter & x);

    inline void from_json(const json & j, launch_fighter& x) {
        x.event = j.at("event").get<std::string>();
        x.id = j.at("ID").get<int64_t>();
        x.loadout = j.at("Loadout").get<std::string>();
        x.player_controlled = j.at("PlayerControlled").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const launch_fighter & x) {
        j = json::object();
        j["event"] = x.event;
        j["ID"] = x.id;
        j["Loadout"] = x.loadout;
        j["PlayerControlled"] = x.player_controlled;
        j["timestamp"] = x.timestamp;
    }
}


