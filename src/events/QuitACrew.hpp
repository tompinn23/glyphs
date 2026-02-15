//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     quit_a_crew data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct quit_a_crew {
        /**
         * Helm player's commander name
         */
        std::string captain;
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
    void from_json(const json & j, quit_a_crew & x);
    void to_json(json & j, const quit_a_crew & x);

    inline void from_json(const json & j, quit_a_crew& x) {
        x.captain = j.at("Captain").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.telepresence = get_stack_optional<bool>(j, "Telepresence");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const quit_a_crew & x) {
        j = json::object();
        j["Captain"] = x.captain;
        j["event"] = x.event;
        j["Telepresence"] = x.telepresence;
        j["timestamp"] = x.timestamp;
    }
}


