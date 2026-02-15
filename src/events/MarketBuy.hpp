//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     market_buy data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when purchasing goods in the market
     */
    struct market_buy {
        int64_t buy_price;
        int64_t count;
        std::string event;
        int64_t market_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t total_cost;
        std::string type;
        /**
         * The localised value will be omitted if it is exactly the same as Type
         */
        std::optional<std::string> type_localised;
    };
}

namespace hue {
    void from_json(const json & j, market_buy & x);
    void to_json(json & j, const market_buy & x);

    inline void from_json(const json & j, market_buy& x) {
        x.buy_price = j.at("BuyPrice").get<int64_t>();
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_cost = j.at("TotalCost").get<int64_t>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const market_buy & x) {
        j = json::object();
        j["BuyPrice"] = x.buy_price;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["timestamp"] = x.timestamp;
        j["TotalCost"] = x.total_cost;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


