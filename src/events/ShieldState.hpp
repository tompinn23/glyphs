//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     shield_state data = nlohmann::json::parse(jsonString);

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
     * When written: when shields are disabled in combat, or recharged
     */
    struct shield_state {
        std::string event;
        /**
         * false when disabled, true when restored
         */
        bool shields_up;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, shield_state & x);
    void to_json(json & j, const shield_state & x);

    inline void from_json(const json & j, shield_state& x) {
        x.event = j.at("event").get<std::string>();
        x.shields_up = j.at("ShieldsUp").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const shield_state & x) {
        j = json::object();
        j["event"] = x.event;
        j["ShieldsUp"] = x.shields_up;
        j["timestamp"] = x.timestamp;
    }
}


