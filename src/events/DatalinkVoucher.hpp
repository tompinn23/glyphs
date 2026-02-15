//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     datalink_voucher data = nlohmann::json::parse(jsonString);

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
     * When written: when scanning a datalink generates a reward
     */
    struct datalink_voucher {
        std::string event;
        std::string payee_faction;
        int64_t reward;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string victim_faction;
    };
}

namespace hue {
    void from_json(const json & j, datalink_voucher & x);
    void to_json(json & j, const datalink_voucher & x);

    inline void from_json(const json & j, datalink_voucher& x) {
        x.event = j.at("event").get<std::string>();
        x.payee_faction = j.at("PayeeFaction").get<std::string>();
        x.reward = j.at("Reward").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.victim_faction = j.at("VictimFaction").get<std::string>();
    }

    inline void to_json(json & j, const datalink_voucher & x) {
        j = json::object();
        j["event"] = x.event;
        j["PayeeFaction"] = x.payee_faction;
        j["Reward"] = x.reward;
        j["timestamp"] = x.timestamp;
        j["VictimFaction"] = x.victim_faction;
    }
}


