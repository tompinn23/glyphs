//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     buy_drones data = nlohmann::json::parse(jsonString);

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
     * When Written: when purchasing drones
     */
    struct buy_drones {
        int64_t buy_price;
        int64_t count;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t total_cost;
        std::string type;
    };
}

namespace hue {
    void from_json(const json & j, buy_drones & x);
    void to_json(json & j, const buy_drones & x);

    inline void from_json(const json & j, buy_drones& x) {
        x.buy_price = j.at("BuyPrice").get<int64_t>();
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_cost = j.at("TotalCost").get<int64_t>();
        x.type = j.at("Type").get<std::string>();
    }

    inline void to_json(json & j, const buy_drones & x) {
        j = json::object();
        j["BuyPrice"] = x.buy_price;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["TotalCost"] = x.total_cost;
        j["Type"] = x.type;
    }
}


