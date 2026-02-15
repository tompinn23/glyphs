//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     sell_drones data = nlohmann::json::parse(jsonString);

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
     * When Written: when selling unwanted drones back to the market
     */
    struct sell_drones {
        int64_t count;
        std::string event;
        int64_t sell_price;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t total_sale;
        std::string type;
    };
}

namespace hue {
    void from_json(const json & j, sell_drones & x);
    void to_json(json & j, const sell_drones & x);

    inline void from_json(const json & j, sell_drones& x) {
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.sell_price = j.at("SellPrice").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_sale = j.at("TotalSale").get<int64_t>();
        x.type = j.at("Type").get<std::string>();
    }

    inline void to_json(json & j, const sell_drones & x) {
        j = json::object();
        j["Count"] = x.count;
        j["event"] = x.event;
        j["SellPrice"] = x.sell_price;
        j["timestamp"] = x.timestamp;
        j["TotalSale"] = x.total_sale;
        j["Type"] = x.type;
    }
}


