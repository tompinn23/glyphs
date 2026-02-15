//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     sell_exploration_data data = nlohmann::json::parse(jsonString);

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
     * When Written: when selling exploration data in Cartographics
     */
    struct sell_exploration_data {
        int64_t base_value;
        /**
         * Bonus for first discoveries
         */
        int64_t bonus;
        std::vector<std::string> discovered;
        std::string event;
        std::vector<std::string> systems;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Total credits received (including for example the 200% bonus if rank 5 with Li Yong Rui)
         */
        int64_t total_earnings;
    };
}

namespace hue {
    void from_json(const json & j, sell_exploration_data & x);
    void to_json(json & j, const sell_exploration_data & x);

    inline void from_json(const json & j, sell_exploration_data& x) {
        x.base_value = j.at("BaseValue").get<int64_t>();
        x.bonus = j.at("Bonus").get<int64_t>();
        x.discovered = j.at("Discovered").get<std::vector<std::string>>();
        x.event = j.at("event").get<std::string>();
        x.systems = j.at("Systems").get<std::vector<std::string>>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_earnings = j.at("TotalEarnings").get<int64_t>();
    }

    inline void to_json(json & j, const sell_exploration_data & x) {
        j = json::object();
        j["BaseValue"] = x.base_value;
        j["Bonus"] = x.bonus;
        j["Discovered"] = x.discovered;
        j["event"] = x.event;
        j["Systems"] = x.systems;
        j["timestamp"] = x.timestamp;
        j["TotalEarnings"] = x.total_earnings;
    }
}


