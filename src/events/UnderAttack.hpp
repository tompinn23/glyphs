//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     under_attack data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when under fire (same time as the Under Attack voice message)
     */
    struct under_attack {
        std::string event;
        std::optional<std::string> target;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, under_attack & x);
    void to_json(json & j, const under_attack & x);

    inline void from_json(const json & j, under_attack& x) {
        x.event = j.at("event").get<std::string>();
        x.target = get_stack_optional<std::string>(j, "Target");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const under_attack & x) {
        j = json::object();
        j["event"] = x.event;
        j["Target"] = x.target;
        j["timestamp"] = x.timestamp;
    }
}


