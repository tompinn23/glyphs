//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_jump_request data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * At the time the player requests the jump, not the jump itself
     */
    struct carrier_jump_request {
        std::optional<std::string> body;
        int64_t body_id;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::optional<std::string> departure_time;
        std::string event;
        int64_t system_address;
        std::string system_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;

        /* added by us */
        std::optional<std::string> callsign;
    };
}

namespace hue {
    void from_json(const json & j, carrier_jump_request & x);
    void to_json(json & j, const carrier_jump_request & x);

    inline void from_json(const json & j, carrier_jump_request& x) {
        x.body = get_stack_optional<std::string>(j, "Body");
        x.body_id = j.at("BodyID").get<int64_t>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.departure_time = get_stack_optional<std::string>(j, "DepartureTime");
        x.event = j.at("event").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.system_name = j.at("SystemName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_jump_request & x) {
        j = json::object();
        j["Body"] = x.body;
        j["BodyID"] = x.body_id;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["DepartureTime"] = x.departure_time;
        j["event"] = x.event;
        j["SystemAddress"] = x.system_address;
        j["SystemName"] = x.system_name;
        j["Callsign"] = x.callsign;
        j["timestamp"] = x.timestamp;
    }
}


