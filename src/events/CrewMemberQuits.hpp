//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     crew_member_quits data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: When another player leaves your ship's crew
     */
    struct crew_member_quits {
        /**
         * Player's commander name
         */
        std::string crew;
        std::string event;
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
    void from_json(const json & j, crew_member_quits & x);
    void to_json(json & j, const crew_member_quits & x);

    inline void from_json(const json & j, crew_member_quits& x) {
        x.crew = j.at("Crew").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.telepresence = get_stack_optional<bool>(j, "Telepresence");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const crew_member_quits & x) {
        j = json::object();
        j["Crew"] = x.crew;
        j["event"] = x.event;
        j["Telepresence"] = x.telepresence;
        j["timestamp"] = x.timestamp;
    }
}


