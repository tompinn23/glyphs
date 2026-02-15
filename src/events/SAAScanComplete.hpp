//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     saa_scan_complete data = nlohmann::json::parse(jsonString);

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
     * When written: after using the Surface Area Analysis Scanner
     */
    struct saa_scan_complete {
        int64_t body_id;
        std::string body_name;
        int64_t efficiency_target;
        std::string event;
        int64_t probes_used;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, saa_scan_complete & x);
    void to_json(json & j, const saa_scan_complete & x);

    inline void from_json(const json & j, saa_scan_complete& x) {
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_name = j.at("BodyName").get<std::string>();
        x.efficiency_target = j.at("EfficiencyTarget").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.probes_used = j.at("ProbesUsed").get<int64_t>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const saa_scan_complete & x) {
        j = json::object();
        j["BodyID"] = x.body_id;
        j["BodyName"] = x.body_name;
        j["EfficiencyTarget"] = x.efficiency_target;
        j["event"] = x.event;
        j["ProbesUsed"] = x.probes_used;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


