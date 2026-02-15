//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     pvp_kill data = nlohmann::json::parse(jsonString);

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
     * When written: when this player has killed another player
     */
    struct pvp_kill {
        /**
         * VictimΓÇÖs rank in range 0..8
         */
        int64_t combat_rank;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Name of the victim
         */
        std::string victim;
    };
}

namespace hue {
    void from_json(const json & j, pvp_kill & x);
    void to_json(json & j, const pvp_kill & x);

    inline void from_json(const json & j, pvp_kill& x) {
        x.combat_rank = j.at("CombatRank").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.victim = j.at("Victim").get<std::string>();
    }

    inline void to_json(json & j, const pvp_kill & x) {
        j = json::object();
        j["CombatRank"] = x.combat_rank;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["Victim"] = x.victim;
    }
}


