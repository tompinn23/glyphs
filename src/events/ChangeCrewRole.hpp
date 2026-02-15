//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     change_crew_role data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when in a crew on someone else's ship, player switched crew role
     */
    struct change_crew_role {
        std::string event;
        std::string role;
        /**
         * Only from Odyssey build
         */
        std::optional<bool> telepresence;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, change_crew_role & x);
    void to_json(json & j, const change_crew_role & x);

    inline void from_json(const json & j, change_crew_role& x) {
        x.event = j.at("event").get<std::string>();
        x.role = j.at("Role").get<std::string>();
        x.telepresence = get_stack_optional<bool>(j, "Telepresence");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const change_crew_role & x) {
        j = json::object();
        j["event"] = x.event;
        j["Role"] = x.role;
        j["Telepresence"] = x.telepresence;
        j["timestamp"] = x.timestamp;
    }
}


