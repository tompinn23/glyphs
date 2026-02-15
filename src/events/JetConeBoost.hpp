//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     jet_cone_boost data = nlohmann::json::parse(jsonString);

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
     * When written: when enough material has been collected from a solar jet code (at a white
     * dwarf or neutron star) for a jump boost
     */
    struct jet_cone_boost {
        double boost_value;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, jet_cone_boost & x);
    void to_json(json & j, const jet_cone_boost & x);

    inline void from_json(const json & j, jet_cone_boost& x) {
        x.boost_value = j.at("BoostValue").get<double>();
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const jet_cone_boost & x) {
        j = json::object();
        j["BoostValue"] = x.boost_value;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
    }
}


