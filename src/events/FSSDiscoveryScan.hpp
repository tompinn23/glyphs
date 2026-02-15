//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fss_discovery_scan data = nlohmann::json::parse(jsonString);

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
     * When written: when performing a full system scan (Honk)
     */
    struct fss_discovery_scan {
        int64_t body_count;
        std::string event;
        int64_t non_body_count;
        double progress;
        int64_t system_address;
        std::string system_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, fss_discovery_scan & x);
    void to_json(json & j, const fss_discovery_scan & x);

    inline void from_json(const json & j, fss_discovery_scan& x) {
        x.body_count = j.at("BodyCount").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.non_body_count = j.at("NonBodyCount").get<int64_t>();
        x.progress = j.at("Progress").get<double>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.system_name = j.at("SystemName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const fss_discovery_scan & x) {
        j = json::object();
        j["BodyCount"] = x.body_count;
        j["event"] = x.event;
        j["NonBodyCount"] = x.non_body_count;
        j["Progress"] = x.progress;
        j["SystemAddress"] = x.system_address;
        j["SystemName"] = x.system_name;
        j["timestamp"] = x.timestamp;
    }
}


