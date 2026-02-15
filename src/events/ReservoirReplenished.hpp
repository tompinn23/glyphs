//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     reservoir_replenished data = nlohmann::json::parse(jsonString);

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
     * When fuel is moved from one fuel tank to another
     */
    struct reservoir_replenished {
        std::string event;
        double fuel_main;
        double fuel_reservoir;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, reservoir_replenished & x);
    void to_json(json & j, const reservoir_replenished & x);

    inline void from_json(const json & j, reservoir_replenished& x) {
        x.event = j.at("event").get<std::string>();
        x.fuel_main = j.at("FuelMain").get<double>();
        x.fuel_reservoir = j.at("FuelReservoir").get<double>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const reservoir_replenished & x) {
        j = json::object();
        j["event"] = x.event;
        j["FuelMain"] = x.fuel_main;
        j["FuelReservoir"] = x.fuel_reservoir;
        j["timestamp"] = x.timestamp;
    }
}


