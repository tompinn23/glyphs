//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     buy_exploration_data data = nlohmann::json::parse(jsonString);

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
     * When Written: when buying system data via the galaxy map
     */
    struct buy_exploration_data {
        int64_t cost;
        std::string event;
        std::string system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, buy_exploration_data & x);
    void to_json(json & j, const buy_exploration_data & x);

    inline void from_json(const json & j, buy_exploration_data& x) {
        x.cost = j.at("Cost").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.system = j.at("System").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const buy_exploration_data & x) {
        j = json::object();
        j["Cost"] = x.cost;
        j["event"] = x.event;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
    }
}


