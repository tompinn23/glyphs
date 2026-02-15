//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     kick_crew_member data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: When you force another player to leave your ship's crew
     */
    struct kick_crew_member {
        std::string crew;
        std::string event;
        /**
         * True if player is automatically kicked for committing a crime in a lawful session
         */
        bool on_crime;
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
    void from_json(const json & j, kick_crew_member & x);
    void to_json(json & j, const kick_crew_member & x);

    inline void from_json(const json & j, kick_crew_member& x) {
        x.crew = j.at("Crew").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.on_crime = j.at("OnCrime").get<bool>();
        x.telepresence = get_stack_optional<bool>(j, "Telepresence");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const kick_crew_member & x) {
        j = json::object();
        j["Crew"] = x.crew;
        j["event"] = x.event;
        j["OnCrime"] = x.on_crime;
        j["Telepresence"] = x.telepresence;
        j["timestamp"] = x.timestamp;
    }
}


