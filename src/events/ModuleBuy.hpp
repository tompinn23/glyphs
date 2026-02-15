//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_buy data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when buying a module in outfitting
     */
    struct module_buy {
        /**
         * The module being purchased
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
         * If existing module in slot is sold
         */
        std::optional<std::string> sell_item;
        /**
         * If existing module in slot is sold
         */
        std::optional<std::string> sell_item_localised;
        /**
         * If existing module in slot is sold
         */
        std::optional<int64_t> sell_price;
        /**
         * The player's ship
         */
        std::string ship;
        /**
         * The player's ship ID
         */
        int64_t ship_id;
        /**
         * Slot that is outfitted
         */
        std::string slot;
        /**
         * If existing module in slot is stored
         */
        std::optional<std::string> stored_item;
        /**
         * If existing module in slot is stored
         */
        std::optional<std::string> stored_item_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, module_buy & x);
    void to_json(json & j, const module_buy & x);

    inline void from_json(const json & j, module_buy& x) {
        x.buy_item = j.at("BuyItem").get<std::string>();
        x.buy_item_localised = get_stack_optional<std::string>(j, "BuyItem_Localised");
        x.buy_price = j.at("BuyPrice").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.sell_item = get_stack_optional<std::string>(j, "SellItem");
        x.sell_item_localised = get_stack_optional<std::string>(j, "SellItem_Localised");
        x.sell_price = get_stack_optional<int64_t>(j, "SellPrice");
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.slot = j.at("Slot").get<std::string>();
        x.stored_item = get_stack_optional<std::string>(j, "StoredItem");
        x.stored_item_localised = get_stack_optional<std::string>(j, "StoredItem_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const module_buy & x) {
        j = json::object();
        j["BuyItem"] = x.buy_item;
        j["BuyItem_Localised"] = x.buy_item_localised;
        j["BuyPrice"] = x.buy_price;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["SellItem"] = x.sell_item;
        j["SellItem_Localised"] = x.sell_item_localised;
        j["SellPrice"] = x.sell_price;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["Slot"] = x.slot;
        j["StoredItem"] = x.stored_item;
        j["StoredItem_Localised"] = x.stored_item_localised;
        j["timestamp"] = x.timestamp;
    }
}


