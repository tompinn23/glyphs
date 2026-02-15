//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay_voucher data = nlohmann::json::parse(jsonString);

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
     * When written: when receiving payment for powerplay combat
     */
    struct powerplay_voucher {
        std::string event;
        std::string power;
        std::vector<std::string> systems;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, powerplay_voucher & x);
    void to_json(json & j, const powerplay_voucher & x);

    inline void from_json(const json & j, powerplay_voucher& x) {
        x.event = j.at("event").get<std::string>();
        x.power = j.at("Power").get<std::string>();
        x.systems = j.at("Systems").get<std::vector<std::string>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const powerplay_voucher & x) {
        j = json::object();
        j["event"] = x.event;
        j["Power"] = x.power;
        j["Systems"] = x.systems;
        j["timestamp"] = x.timestamp;
    }
}


