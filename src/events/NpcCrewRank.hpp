//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     npc_crew_rank data = nlohmann::json::parse(jsonString);

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
     * This is written when a crew member's combat rank increases
     */
    struct npc_crew_rank {
        std::string event;
        int64_t npc_crew_id;
        std::string npc_crew_name;
        int64_t rank_combat;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, npc_crew_rank & x);
    void to_json(json & j, const npc_crew_rank & x);

    inline void from_json(const json & j, npc_crew_rank& x) {
        x.event = j.at("event").get<std::string>();
        x.npc_crew_id = j.at("NpcCrewId").get<int64_t>();
        x.npc_crew_name = j.at("NpcCrewName").get<std::string>();
        x.rank_combat = j.at("RankCombat").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const npc_crew_rank & x) {
        j = json::object();
        j["event"] = x.event;
        j["NpcCrewId"] = x.npc_crew_id;
        j["NpcCrewName"] = x.npc_crew_name;
        j["RankCombat"] = x.rank_combat;
        j["timestamp"] = x.timestamp;
    }
}


