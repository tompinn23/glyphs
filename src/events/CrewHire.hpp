//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     crew_hire data = nlohmann::json::parse(jsonString);

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
     * When written: when engaging a new member of crew
     */
    struct crew_hire {
        int64_t combat_rank;
        int64_t cost;
        int64_t crew_id;
        std::string event;
        std::string faction;
        std::string name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, crew_hire & x);
    void to_json(json & j, const crew_hire & x);

    inline void from_json(const json & j, crew_hire& x) {
        x.combat_rank = j.at("CombatRank").get<int64_t>();
        x.cost = j.at("Cost").get<int64_t>();
        x.crew_id = j.at("CrewID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.faction = j.at("Faction").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const crew_hire & x) {
        j = json::object();
        j["CombatRank"] = x.combat_rank;
        j["Cost"] = x.cost;
        j["CrewID"] = x.crew_id;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["Name"] = x.name;
        j["timestamp"] = x.timestamp;
    }
}


