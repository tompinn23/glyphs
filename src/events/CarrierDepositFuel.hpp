//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_deposit_fuel data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * Any player giving fuel to the carrier
     */
    struct carrier_deposit_fuel {
        int64_t amount;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Total amount of fuel after donation
         */
        int64_t total;
    };
}

namespace hue {
    void from_json(const json & j, carrier_deposit_fuel & x);
    void to_json(json & j, const carrier_deposit_fuel & x);

    inline void from_json(const json & j, carrier_deposit_fuel& x) {
        x.amount = j.at("Amount").get<int64_t>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total = j.at("Total").get<int64_t>();
    }

    inline void to_json(json & j, const carrier_deposit_fuel & x) {
        j = json::object();
        j["Amount"] = x.amount;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["Total"] = x.total;
    }
}


