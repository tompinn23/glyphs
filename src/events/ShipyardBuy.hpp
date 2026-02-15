//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     shipyard_buy data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when buying a new ship in the shipyard
     */
    struct shipyard_buy {
        std::string event;
        int64_t market_id;
        /**
         * If selling current ship
         */
        std::optional<std::string> sell_old_ship;
        /**
         * If selling current ship
         */
        std::optional<int64_t> sell_price;
        /**
         * If selling current ship
         */
        std::optional<int64_t> sell_ship_id;
        int64_t ship_price;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        /**
         * If storing old ship
         */
        std::optional<std::string> store_old_ship;
        /**
         * If storing old ship
         */
        std::optional<int64_t> store_ship_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, shipyard_buy & x);
    void to_json(json & j, const shipyard_buy & x);

    inline void from_json(const json & j, shipyard_buy& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.sell_old_ship = get_stack_optional<std::string>(j, "SellOldShip");
        x.sell_price = get_stack_optional<int64_t>(j, "SellPrice");
        x.sell_ship_id = get_stack_optional<int64_t>(j, "SellShipID");
        x.ship_price = j.at("ShipPrice").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.store_old_ship = get_stack_optional<std::string>(j, "StoreOldShip");
        x.store_ship_id = get_stack_optional<int64_t>(j, "StoreShipID");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const shipyard_buy & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["SellOldShip"] = x.sell_old_ship;
        j["SellPrice"] = x.sell_price;
        j["SellShipID"] = x.sell_ship_id;
        j["ShipPrice"] = x.ship_price;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["StoreOldShip"] = x.store_old_ship;
        j["StoreShipID"] = x.store_ship_id;
        j["timestamp"] = x.timestamp;
    }
}


