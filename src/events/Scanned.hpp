//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     scanned data = nlohmann::json::parse(jsonString);

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
     * When written: when the player's ship has been scanned (The Scan Detected indication is at
     * the start of the scan, this is written at the end of a successful scan)
     */
    struct scanned {
        std::string event;
        std::string scan_type;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, scanned & x);
    void to_json(json & j, const scanned & x);

    inline void from_json(const json & j, scanned& x) {
        x.event = j.at("event").get<std::string>();
        x.scan_type = j.at("ScanType").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const scanned & x) {
        j = json::object();
        j["event"] = x.event;
        j["ScanType"] = x.scan_type;
        j["timestamp"] = x.timestamp;
    }
}


