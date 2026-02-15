//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay_merits data = nlohmann::json::parse(jsonString);

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
     * When written: when receiving salary payment from a power
     */
    struct powerplay_merits {
        std::string event;
        int64_t merits_gained;
        std::string power;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t total_merits;
    };
}

namespace hue {
    void from_json(const json & j, powerplay_merits & x);
    void to_json(json & j, const powerplay_merits & x);

    inline void from_json(const json & j, powerplay_merits& x) {
        x.event = j.at("event").get<std::string>();
        x.merits_gained = j.at("MeritsGained").get<int64_t>();
        x.power = j.at("Power").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_merits = j.at("TotalMerits").get<int64_t>();
    }

    inline void to_json(json & j, const powerplay_merits & x) {
        j = json::object();
        j["event"] = x.event;
        j["MeritsGained"] = x.merits_gained;
        j["Power"] = x.power;
        j["timestamp"] = x.timestamp;
        j["TotalMerits"] = x.total_merits;
    }
}


