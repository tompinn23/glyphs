//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     shipyard_sell data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when selling a ship stored in the shipyard
     */
    struct shipyard_sell {
        std::string event;
        int64_t market_id;
        int64_t sell_ship_id;
        std::optional<int64_t> ship_market_id;
        int64_t ship_price;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        /**
         * If ship is in another system
         */
        std::optional<std::string> system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, shipyard_sell & x);
    void to_json(json & j, const shipyard_sell & x);

    inline void from_json(const json & j, shipyard_sell& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.sell_ship_id = j.at("SellShipID").get<int64_t>();
        x.ship_market_id = get_stack_optional<int64_t>(j, "ShipMarketID");
        x.ship_price = j.at("ShipPrice").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.system = get_stack_optional<std::string>(j, "System");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const shipyard_sell & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["SellShipID"] = x.sell_ship_id;
        j["ShipMarketID"] = x.ship_market_id;
        j["ShipPrice"] = x.ship_price;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
    }
}


