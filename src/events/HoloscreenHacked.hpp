//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     holoscreen_hacked data = nlohmann::json::parse(jsonString);

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
     * When a holoscreen is hacked
     */
    struct holoscreen_hacked {
        std::string event;
        /**
         * The power that now owns the holo screen
         */
        std::string power_after;
        /**
         * The power that owned the holo screen
         */
        std::string power_before;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, holoscreen_hacked & x);
    void to_json(json & j, const holoscreen_hacked & x);

    inline void from_json(const json & j, holoscreen_hacked& x) {
        x.event = j.at("event").get<std::string>();
        x.power_after = j.at("PowerAfter").get<std::string>();
        x.power_before = j.at("PowerBefore").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const holoscreen_hacked & x) {
        j = json::object();
        j["event"] = x.event;
        j["PowerAfter"] = x.power_after;
        j["PowerBefore"] = x.power_before;
        j["timestamp"] = x.timestamp;
    }
}


