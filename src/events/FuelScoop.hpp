//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fuel_scoop data = nlohmann::json::parse(jsonString);

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
     * When written: when scooping fuel from a star
     */
    struct fuel_scoop {
        std::string event;
        /**
         * Tons fuel scooped
         */
        double scooped;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Total fuel level after scooping
         */
        double total;
    };
}

namespace hue {
    void from_json(const json & j, fuel_scoop & x);
    void to_json(json & j, const fuel_scoop & x);

    inline void from_json(const json & j, fuel_scoop& x) {
        x.event = j.at("event").get<std::string>();
        x.scooped = j.at("Scooped").get<double>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total = j.at("Total").get<double>();
    }

    inline void to_json(json & j, const fuel_scoop & x) {
        j = json::object();
        j["event"] = x.event;
        j["Scooped"] = x.scooped;
        j["timestamp"] = x.timestamp;
        j["Total"] = x.total;
    }
}


