//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     approach_body data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"

namespace hue {
    using nlohmann::json;
    /**
     * When written: when in Supercruise, and distance from planet drops to within the 'Orbital
     * Cruise' zone
     */
    struct approach_body {
        std::string body;
        int64_t body_id;
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
    void from_json(const json & j, approach_body & x);
    void to_json(json & j, const approach_body & x);

    inline void from_json(const json & j, approach_body& x) {
        x.body = j.at("Body").get<std::string>();
        x.body_id = j.at("BodyID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const approach_body & x) {
        j = json::object();
        j["Body"] = x.body;
        j["BodyID"] = x.body_id;
        j["event"] = x.event;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}
