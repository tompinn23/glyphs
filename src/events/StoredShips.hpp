//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     stored_ships data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;




    struct local_ships {
        bool hot;
        std::optional<std::string> name;
        int64_t ship_id;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        int64_t value;
    };

    struct remote_ships {
        bool hot;
        /**
         * If the ship is in transit
         */
        std::optional<bool> in_transit;
        std::optional<std::string> name;
        int64_t ship_id;
        /**
         * If the ship is not in transit
         */
        std::optional<int64_t> ship_market_id;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        /**
         * If the ship is not in transit
         */
        std::optional<std::string> star_system;
        /**
         * If the ship is not in transit
         */
        std::optional<int64_t> transfer_price;
        /**
         * If the ship is not in transit
         */
        std::optional<int64_t> transfer_time;
        int64_t value;
    };

    /**
     * When written: when visiting shipyard
     */
    struct stored_ships {
        std::string event;
        int64_t market_id;
        std::vector<local_ships> ships_here;
        std::vector<remote_ships> ships_remote;
        std::string star_system;
        std::string station_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    inline void from_json(const json & j, local_ships& x) {
        x.hot = j.at("Hot").get<bool>();
        x.name = get_stack_optional<std::string>(j, "Name");
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.value = j.at("Value").get<int64_t>();
    }

    inline void to_json(json & j, const local_ships & x) {
        j = json::object();
        j["Hot"] = x.hot;
        j["Name"] = x.name;
        j["ShipID"] = x.ship_id;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["Value"] = x.value;
    }

    inline void from_json(const json & j, remote_ships& x) {
        x.hot = j.at("Hot").get<bool>();
        x.in_transit = get_stack_optional<bool>(j, "InTransit");
        x.name = get_stack_optional<std::string>(j, "Name");
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.ship_market_id = get_stack_optional<int64_t>(j, "ShipMarketID");
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.star_system = get_stack_optional<std::string>(j, "StarSystem");
        x.transfer_price = get_stack_optional<int64_t>(j, "TransferPrice");
        x.transfer_time = get_stack_optional<int64_t>(j, "TransferTime");
        x.value = j.at("Value").get<int64_t>();
    }

    inline void to_json(json & j, const remote_ships & x) {
        j = json::object();
        j["Hot"] = x.hot;
        j["InTransit"] = x.in_transit;
        j["Name"] = x.name;
        j["ShipID"] = x.ship_id;
        j["ShipMarketID"] = x.ship_market_id;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["StarSystem"] = x.star_system;
        j["TransferPrice"] = x.transfer_price;
        j["TransferTime"] = x.transfer_time;
        j["Value"] = x.value;
    }

    inline void from_json(const json & j, stored_ships& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.ships_here = j.at("ShipsHere").get<std::vector<local_ships>>();
        x.ships_remote = j.at("ShipsRemote").get<std::vector<remote_ships>>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_name = j.at("StationName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const stored_ships & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["ShipsHere"] = x.ships_here;
        j["ShipsRemote"] = x.ships_remote;
        j["StarSystem"] = x.star_system;
        j["StationName"] = x.station_name;
        j["timestamp"] = x.timestamp;
    }
}


