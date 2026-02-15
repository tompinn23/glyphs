//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay_defect data = nlohmann::json::parse(jsonString);

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
     * When written: when a player defects from one power to another
     */
    struct powerplay_defect {
        std::string event;
        std::string from_power;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string to_power;
    };
}

namespace hue {
    void from_json(const json & j, powerplay_defect & x);
    void to_json(json & j, const powerplay_defect & x);

    inline void from_json(const json & j, powerplay_defect& x) {
        x.event = j.at("event").get<std::string>();
        x.from_power = j.at("FromPower").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.to_power = j.at("ToPower").get<std::string>();
    }

    inline void to_json(json & j, const powerplay_defect & x) {
        j = json::object();
        j["event"] = x.event;
        j["FromPower"] = x.from_power;
        j["timestamp"] = x.timestamp;
        j["ToPower"] = x.to_power;
    }
}


