//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_crew_services data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * Changes to crew
     */
    struct carrier_crew_services {
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string crew_name;
        std::string crew_role;
        std::string event;
        std::string operation;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_crew_services & x);
    void to_json(json & j, const carrier_crew_services & x);

    inline void from_json(const json & j, carrier_crew_services& x) {
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.crew_name = j.at("CrewName").get<std::string>();
        x.crew_role = j.at("CrewRole").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.operation = j.at("Operation").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_crew_services & x) {
        j = json::object();
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["CrewName"] = x.crew_name;
        j["CrewRole"] = x.crew_role;
        j["event"] = x.event;
        j["Operation"] = x.operation;
        j["timestamp"] = x.timestamp;
    }
}


