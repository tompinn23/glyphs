//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_jump_cancelled data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * This is logged when a jump is cancelled
     */
    struct carrier_jump_cancelled {
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<std::string> callsign;
    };
}

namespace hue {
    void from_json(const json & j, carrier_jump_cancelled & x);
    void to_json(json & j, const carrier_jump_cancelled & x);

    inline void from_json(const json & j, carrier_jump_cancelled& x) {
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_jump_cancelled & x) {
        j = json::object();
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["Callsign"] = x.callsign;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
    }
}


