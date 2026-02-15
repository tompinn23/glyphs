//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_buy data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * Player has bought a fleet carrier
     */
    struct carrier_buy {
        int64_t bought_at_market;
        std::string callsign;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        std::string location;
        int64_t price;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string variant;
    };
}

namespace hue {
    void from_json(const json & j, carrier_buy & x);
    void to_json(json & j, const carrier_buy & x);

    inline void from_json(const json & j, carrier_buy& x) {
        x.bought_at_market = j.at("BoughtAtMarket").get<int64_t>();
        x.callsign = j.at("Callsign").get<std::string>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.location = j.at("Location").get<std::string>();
        x.price = j.at("Price").get<int64_t>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.variant = j.at("Variant").get<std::string>();
    }

    inline void to_json(json & j, const carrier_buy & x) {
        j = json::object();
        j["BoughtAtMarket"] = x.bought_at_market;
        j["Callsign"] = x.callsign;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["event"] = x.event;
        j["Location"] = x.location;
        j["Price"] = x.price;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
        j["Variant"] = x.variant;
    }
}


