//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     set_user_ship_name data = nlohmann::json::parse(jsonString);

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
     * When written: when assigning a name to the ship in Starport Services
     */
    struct set_user_ship_name {
        std::string event;
        std::string ship;
        int64_t ship_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string user_ship_id;
        std::string user_ship_name;
    };
}

namespace hue {
    void from_json(const json & j, set_user_ship_name & x);
    void to_json(json & j, const set_user_ship_name & x);

    inline void from_json(const json & j, set_user_ship_name& x) {
        x.event = j.at("event").get<std::string>();
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.user_ship_id = j.at("UserShipId").get<std::string>();
        x.user_ship_name = j.at("UserShipName").get<std::string>();
    }

    inline void to_json(json & j, const set_user_ship_name & x) {
        j = json::object();
        j["event"] = x.event;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["timestamp"] = x.timestamp;
        j["UserShipId"] = x.user_ship_id;
        j["UserShipName"] = x.user_ship_name;
    }
}


