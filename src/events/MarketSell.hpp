//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     market_sell data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when selling goods in the market
     */
    struct market_sell {
        /**
         * Average price paid
         */
        int64_t avg_price_paid;
        /**
         * Whether selling in a black market
         */
        std::optional<bool> black_market;
        int64_t count;
        std::string event;
        /**
         * Whether goods are illegal here
         */
        std::optional<bool> illegal_goods;
        int64_t market_id;
        /**
         * Price per unit
         */
        int64_t sell_price;
        /**
         * Whether goods were stolen
         */
        std::optional<bool> stolen_goods;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Total sale value
         */
        int64_t total_sale;
        std::string type;
        /**
         * The localised value will be omitted if it is exactly the same as Type
         */
        std::optional<std::string> type_localised;
    };
}

namespace hue {
    void from_json(const json & j, market_sell & x);
    void to_json(json & j, const market_sell & x);

    inline void from_json(const json & j, market_sell& x) {
        x.avg_price_paid = j.at("AvgPricePaid").get<int64_t>();
        x.black_market = get_stack_optional<bool>(j, "BlackMarket");
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.illegal_goods = get_stack_optional<bool>(j, "IllegalGoods");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.sell_price = j.at("SellPrice").get<int64_t>();
        x.stolen_goods = get_stack_optional<bool>(j, "StolenGoods");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_sale = j.at("TotalSale").get<int64_t>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const market_sell & x) {
        j = json::object();
        j["AvgPricePaid"] = x.avg_price_paid;
        j["BlackMarket"] = x.black_market;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["IllegalGoods"] = x.illegal_goods;
        j["MarketID"] = x.market_id;
        j["SellPrice"] = x.sell_price;
        j["StolenGoods"] = x.stolen_goods;
        j["timestamp"] = x.timestamp;
        j["TotalSale"] = x.total_sale;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


