//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     cap_ship_bond data = nlohmann::json::parse(jsonString);

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
     * When written: The player has been rewarded for a capital ship combat
     */
    struct cap_ship_bond {
        std::string awarding_faction;
        std::string event;
        int64_t reward;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string victim_faction;
    };
}

namespace hue {
    void from_json(const json & j, cap_ship_bond & x);
    void to_json(json & j, const cap_ship_bond & x);

    inline void from_json(const json & j, cap_ship_bond& x) {
        x.awarding_faction = j.at("AwardingFaction").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.reward = j.at("Reward").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.victim_faction = j.at("VictimFaction").get<std::string>();
    }

    inline void to_json(json & j, const cap_ship_bond & x) {
        j = json::object();
        j["AwardingFaction"] = x.awarding_faction;
        j["event"] = x.event;
        j["Reward"] = x.reward;
        j["timestamp"] = x.timestamp;
        j["VictimFaction"] = x.victim_faction;
    }
}


