//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     sell_ship_on_rebuy data = nlohmann::json::parse(jsonString);

#pragma once

#include "nlohmann/json.hpp"

namespace hue {
    using nlohmann::json;

    #ifndef NLOHMANN_UNTYPED_hue_HELPER
    #define NLOHMANN_UNTYPED_hue_HELPER
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    #endif

    /**
     * When written: When selling a stored ship to raise funds when on insurance/rebuy screen
     */
    struct sell_ship_on_rebuy {
        std::string event;
        int64_t sell_ship_id;
        int64_t ship_price;
        std::string ship_type;
        std::string system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, sell_ship_on_rebuy & x);
    void to_json(json & j, const sell_ship_on_rebuy & x);

    inline void from_json(const json & j, sell_ship_on_rebuy& x) {
        x.event = j.at("event").get<std::string>();
        x.sell_ship_id = j.at("SellShipId").get<int64_t>();
        x.ship_price = j.at("ShipPrice").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.system = j.at("System").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const sell_ship_on_rebuy & x) {
        j = json::object();
        j["event"] = x.event;
        j["SellShipId"] = x.sell_ship_id;
        j["ShipPrice"] = x.ship_price;
        j["ShipType"] = x.ship_type;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
    }
}


