//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_location data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * Carrier Location. Written on startup and after a carrier jump.
     */
    struct carrier_location {
        int64_t body_id;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        std::string star_system;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_location & x);
    void to_json(json & j, const carrier_location & x);

    inline void from_json(const json & j, carrier_location& x) {
        x.body_id = j.at("BodyID").get<int64_t>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_location & x) {
        j = json::object();
        j["BodyID"] = x.body_id;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["event"] = x.event;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


