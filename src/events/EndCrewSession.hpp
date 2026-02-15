//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     end_crew_session data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when the captain in multicrew disbands the crew
     */
    struct end_crew_session {
        std::string event;
        /**
         * true if crew disbanded as a result of a crime in a lawful session
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
    void from_json(const json & j, end_crew_session & x);
    void to_json(json & j, const end_crew_session & x);

    inline void from_json(const json & j, end_crew_session& x) {
        x.event = j.at("event").get<std::string>();
        x.on_crime = j.at("OnCrime").get<bool>();
        x.telepresence = get_stack_optional<bool>(j, "Telepresence");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const end_crew_session & x) {
        j = json::object();
        j["event"] = x.event;
        j["OnCrime"] = x.on_crime;
        j["Telepresence"] = x.telepresence;
        j["timestamp"] = x.timestamp;
    }
}


