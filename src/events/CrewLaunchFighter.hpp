//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     crew_launch_fighter data = nlohmann::json::parse(jsonString);

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
     * When written: when in multicrew, in Helm player's log, when a crew member launches a
     * fighter
     */
    struct crew_launch_fighter {
        /**
         * Name of crew member launching in fighter
         */
        std::string crew;
        std::string event;
        /**
         * only from Odyssey build
         */
        bool telepresence;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, crew_launch_fighter & x);
    void to_json(json & j, const crew_launch_fighter & x);

    inline void from_json(const json & j, crew_launch_fighter& x) {
        x.crew = j.at("Crew").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.telepresence = j.at("Telepresence").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const crew_launch_fighter & x) {
        j = json::object();
        j["Crew"] = x.crew;
        j["event"] = x.event;
        j["Telepresence"] = x.telepresence;
        j["timestamp"] = x.timestamp;
    }
}


