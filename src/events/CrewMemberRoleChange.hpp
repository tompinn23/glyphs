//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     crew_member_role_change data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: in Multicrew, Helm's log, when another crew player changes role
     */
    struct crew_member_role_change {
        /**
         * Player's commander name
         */
        std::string crew;
        std::string event;
        std::string role;
        /**
         * only from Odyssey build
         */
        std::optional<bool> telepresence;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, crew_member_role_change & x);
    void to_json(json & j, const crew_member_role_change & x);

    inline void from_json(const json & j, crew_member_role_change& x) {
        x.crew = j.at("Crew").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.role = j.at("Role").get<std::string>();
        x.telepresence = get_stack_optional<bool>(j, "Telepresence");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const crew_member_role_change & x) {
        j = json::object();
        j["Crew"] = x.crew;
        j["event"] = x.event;
        j["Role"] = x.role;
        j["Telepresence"] = x.telepresence;
        j["timestamp"] = x.timestamp;
    }
}


