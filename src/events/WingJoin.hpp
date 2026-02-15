//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     wing_join data = nlohmann::json::parse(jsonString);

#pragma once

#include "nlohmann/json.hpp"

namespace hue {
    using nlohmann::json;
    /**
     * When written: this player has joined a wing
     */
    struct wing_join {
        std::string event;
        /**
         * Other player names already in wing
         */
        std::vector<std::string> others;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, wing_join & x);
    void to_json(json & j, const wing_join & x);

    inline void from_json(const json & j, wing_join& x) {
        x.event = j.at("event").get<std::string>();
        x.others = j.at("Others").get<std::vector<std::string>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const wing_join & x) {
        j = json::object();
        j["event"] = x.event;
        j["Others"] = x.others;
        j["timestamp"] = x.timestamp;
    }
}


