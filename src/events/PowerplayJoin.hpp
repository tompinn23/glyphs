//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay_join data = nlohmann::json::parse(jsonString);

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
     * When written: when joining up with a power
     */
    struct powerplay_join {
        std::string event;
        std::string power;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, powerplay_join & x);
    void to_json(json & j, const powerplay_join & x);

    inline void from_json(const json & j, powerplay_join& x) {
        x.event = j.at("event").get<std::string>();
        x.power = j.at("Power").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const powerplay_join & x) {
        j = json::object();
        j["event"] = x.event;
        j["Power"] = x.power;
        j["timestamp"] = x.timestamp;
    }
}


