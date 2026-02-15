//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     clear_impound data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct clear_impound {
        std::string event;
        int64_t market_id;
        int64_t ship_id;
        int64_t ship_market_id;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
        std::optional<std::string> system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, clear_impound & x);
    void to_json(json & j, const clear_impound & x);

    inline void from_json(const json & j, clear_impound& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.ship_market_id = j.at("ShipMarketID").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
        x.system = get_stack_optional<std::string>(j, "System");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const clear_impound & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["ShipID"] = x.ship_id;
        j["ShipMarketID"] = x.ship_market_id;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
    }
}


