//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_sell data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when selling a module in outfitting
     */
    struct module_sell {
        std::string event;
        int64_t market_id;
        std::string sell_item;
        std::optional<std::string> sell_item_localised;
        int64_t sell_price;
        std::string ship;
        int64_t ship_id;
        std::string slot;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, module_sell & x);
    void to_json(json & j, const module_sell & x);

    inline void from_json(const json & j, module_sell& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.sell_item = j.at("SellItem").get<std::string>();
        x.sell_item_localised = get_stack_optional<std::string>(j, "SellItem_Localised");
        x.sell_price = j.at("SellPrice").get<int64_t>();
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.slot = j.at("Slot").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const module_sell & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["SellItem"] = x.sell_item;
        j["SellItem_Localised"] = x.sell_item_localised;
        j["SellPrice"] = x.sell_price;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["Slot"] = x.slot;
        j["timestamp"] = x.timestamp;
    }
}


