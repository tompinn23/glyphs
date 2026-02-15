//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_buy_and_store data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when buying a module and directly storing it in outfitting
     */
    struct module_buy_and_store {
        /**
         * The module being purchased and stored
         */
        std::string buy_item;
        std::optional<std::string> buy_item_localised;
        /**
         * Price paid
         */
        int64_t buy_price;
        std::string event;
        int64_t market_id;
        /**
         * The player's ship
         */
        std::string ship;
        /**
         * The player's ship ID
         */
        int64_t ship_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, module_buy_and_store & x);
    void to_json(json & j, const module_buy_and_store & x);

    inline void from_json(const json & j, module_buy_and_store& x) {
        x.buy_item = j.at("BuyItem").get<std::string>();
        x.buy_item_localised = get_stack_optional<std::string>(j, "BuyItem_Localised");
        x.buy_price = j.at("BuyPrice").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const module_buy_and_store & x) {
        j = json::object();
        j["BuyItem"] = x.buy_item;
        j["BuyItem_Localised"] = x.buy_item_localised;
        j["BuyPrice"] = x.buy_price;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["timestamp"] = x.timestamp;
    }
}


