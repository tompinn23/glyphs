//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     vehicle_switch data = nlohmann::json::parse(jsonString);

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
     * When written: when switching control between the main ship and a fighter
     */
    struct vehicle_switch {
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string to;
    };
}

namespace hue {
    void from_json(const json & j, vehicle_switch & x);
    void to_json(json & j, const vehicle_switch & x);

    inline void from_json(const json & j, vehicle_switch& x) {
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.to = j.at("To").get<std::string>();
    }

    inline void to_json(json & j, const vehicle_switch & x) {
        j = json::object();
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["To"] = x.to;
    }
}


