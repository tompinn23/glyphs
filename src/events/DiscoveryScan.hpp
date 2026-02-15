//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     discovery_scan data = nlohmann::json::parse(jsonString);

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
     * When written: when using the discovery scanner, and new body discoveries are displayed in
     * the cockpit info window. Note you can get two or three of these in a row, where some
     * bodies are discovered by the automatic passive scan, before the active scan is complete.
     */
    struct discovery_scan {
        /**
         * Number of new bodies discovered
         */
        int64_t bodies;
        std::string event;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, discovery_scan & x);
    void to_json(json & j, const discovery_scan & x);

    inline void from_json(const json & j, discovery_scan& x) {
        x.bodies = j.at("Bodies").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const discovery_scan & x) {
        j = json::object();
        j["Bodies"] = x.bodies;
        j["event"] = x.event;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


