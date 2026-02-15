//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     npc_crew_paid_wage data = nlohmann::json::parse(jsonString);

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
     * This is written when crew receive wages
     */
    struct npc_crew_paid_wage {
        int64_t amount;
        std::string event;
        int64_t npc_crew_id;
        std::string npc_crew_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, npc_crew_paid_wage & x);
    void to_json(json & j, const npc_crew_paid_wage & x);

    inline void from_json(const json & j, npc_crew_paid_wage& x) {
        x.amount = j.at("Amount").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.npc_crew_id = j.at("NpcCrewId").get<int64_t>();
        x.npc_crew_name = j.at("NpcCrewName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const npc_crew_paid_wage & x) {
        j = json::object();
        j["Amount"] = x.amount;
        j["event"] = x.event;
        j["NpcCrewId"] = x.npc_crew_id;
        j["NpcCrewName"] = x.npc_crew_name;
        j["timestamp"] = x.timestamp;
    }
}


