//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     nav_beacon_scan data = nlohmann::json::parse(jsonString);

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
     * When written: when scanning a navigation beacon, before the scan data for all the bodies
     * in the system is written into the journal
     */
    struct nav_beacon_scan {
        std::string event;
        int64_t num_bodies;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, nav_beacon_scan & x);
    void to_json(json & j, const nav_beacon_scan & x);

    inline void from_json(const json & j, nav_beacon_scan& x) {
        x.event = j.at("event").get<std::string>();
        x.num_bodies = j.at("NumBodies").get<int64_t>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const nav_beacon_scan & x) {
        j = json::object();
        j["event"] = x.event;
        j["NumBodies"] = x.num_bodies;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


