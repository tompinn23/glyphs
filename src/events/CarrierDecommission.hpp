//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_decommission data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * At the time the player requests decommission
     */
    struct carrier_decommission {
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        int64_t scrap_refund;
        int64_t scrap_time;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_decommission & x);
    void to_json(json & j, const carrier_decommission & x);

    inline void from_json(const json & j, carrier_decommission& x) {
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.scrap_refund = j.at("ScrapRefund").get<int64_t>();
        x.scrap_time = j.at("ScrapTime").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_decommission & x) {
        j = json::object();
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["event"] = x.event;
        j["ScrapRefund"] = x.scrap_refund;
        j["ScrapTime"] = x.scrap_time;
        j["timestamp"] = x.timestamp;
    }
}


