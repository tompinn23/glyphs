//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ship_redeemed data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: after a new ship has been redeemed
     */
    struct ship_redeemed {
        std::string event;
        int64_t new_ship_id;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, ship_redeemed & x);
    void to_json(json & j, const ship_redeemed & x);

    inline void from_json(const json & j, ship_redeemed& x) {
        x.event = j.at("event").get<std::string>();
        x.new_ship_id = j.at("NewShipID").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const ship_redeemed & x) {
        j = json::object();
        j["event"] = x.event;
        j["NewShipID"] = x.new_ship_id;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["timestamp"] = x.timestamp;
    }
}


