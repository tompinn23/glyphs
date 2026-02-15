//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     shipyard_swap data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when switching to another ship already stored at this station
     */
    struct shipyard_swap {
        std::string event;
        int64_t market_id;
        int64_t ship_id;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        std::string store_old_ship;
        int64_t store_ship_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, shipyard_swap & x);
    void to_json(json & j, const shipyard_swap & x);

    inline void from_json(const json & j, shipyard_swap& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.store_old_ship = j.at("StoreOldShip").get<std::string>();
        x.store_ship_id = j.at("StoreShipID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const shipyard_swap & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["ShipID"] = x.ship_id;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["StoreOldShip"] = x.store_old_ship;
        j["StoreShipID"] = x.store_ship_id;
        j["timestamp"] = x.timestamp;
    }
}


