//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     asteroid_cracked data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"

namespace hue {
    /**
     * When written: when the player has broken up a ΓÇÿMotherlodeΓÇÖ asteroid for mining
     */
    struct asteroid_cracked {
        std::string body;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, asteroid_cracked & x);
    void to_json(json & j, const asteroid_cracked & x);

    inline void from_json(const json & j, asteroid_cracked& x) {
        x.body = j.at("Body").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const asteroid_cracked & x) {
        j = json::object();
        j["Body"] = x.body;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
    }
}


