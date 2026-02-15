//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_cancel_decommission data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * At the time the player cancels decommission
     */
    struct carrier_cancel_decommission {
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_cancel_decommission & x);
    void to_json(json & j, const carrier_cancel_decommission & x);

    inline void from_json(const json & j, carrier_cancel_decommission& x) {
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_cancel_decommission & x) {
        j = json::object();
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
    }
}


