//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     shipyard_transfer data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when requesting a ship at another station be transported to this station
     */
    struct shipyard_transfer {
        double distance;
        std::string event;
        int64_t market_id;
        int64_t ship_id;
        int64_t ship_market_id;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        /**
         * Location of the ship
         */
        std::string system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t transfer_price;
        /**
         * Time taken in seconds
         */
        int64_t transfer_time;
    };
}

namespace hue {
    void from_json(const json & j, shipyard_transfer & x);
    void to_json(json & j, const shipyard_transfer & x);

    inline void from_json(const json & j, shipyard_transfer& x) {
        x.distance = j.at("Distance").get<double>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.ship_market_id = j.at("ShipMarketID").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.system = j.at("System").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.transfer_price = j.at("TransferPrice").get<int64_t>();
        x.transfer_time = j.at("TransferTime").get<int64_t>();
    }

    inline void to_json(json & j, const shipyard_transfer & x) {
        j = json::object();
        j["Distance"] = x.distance;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["ShipID"] = x.ship_id;
        j["ShipMarketID"] = x.ship_market_id;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
        j["TransferPrice"] = x.transfer_price;
        j["TransferTime"] = x.transfer_time;
    }
}


