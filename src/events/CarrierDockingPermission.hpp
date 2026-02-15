//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_docking_permission data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * The carrier owner has changed the docking permission criteria
     */
    struct carrier_docking_permission {
        bool allow_notorious;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string docking_access;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_docking_permission & x);
    void to_json(json & j, const carrier_docking_permission & x);

    inline void from_json(const json & j, carrier_docking_permission& x) {
        x.allow_notorious = j.at("AllowNotorious").get<bool>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.docking_access = j.at("DockingAccess").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_docking_permission & x) {
        j = json::object();
        j["AllowNotorious"] = x.allow_notorious;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["DockingAccess"] = x.docking_access;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
    }
}


