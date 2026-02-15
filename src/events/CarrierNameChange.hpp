//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_name_change data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct carrier_name_change {
        std::string callsign;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        std::string name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_name_change & x);
    void to_json(json & j, const carrier_name_change & x);

    inline void from_json(const json & j, carrier_name_change& x) {
        x.callsign = j.at("Callsign").get<std::string>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_name_change & x) {
        j = json::object();
        j["Callsign"] = x.callsign;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["event"] = x.event;
        j["Name"] = x.name;
        j["timestamp"] = x.timestamp;
    }
}


