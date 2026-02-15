//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     supercruise_exit data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: leaving supercruise for normal space
     */
    struct supercruise_exit {
        std::string body;
        int64_t body_id;
        std::string body_type;
        std::string event;
        std::optional<bool> multicrew;
        std::string star_system;
        int64_t system_address;
        std::optional<bool> taxi;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, supercruise_exit & x);
    void to_json(json & j, const supercruise_exit & x);

    inline void from_json(const json & j, supercruise_exit& x) {
        x.body = j.at("Body").get<std::string>();
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_type = j.at("BodyType").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.multicrew = get_stack_optional<bool>(j, "Multicrew");
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.taxi = get_stack_optional<bool>(j, "Taxi");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const supercruise_exit & x) {
        j = json::object();
        j["Body"] = x.body;
        j["BodyID"] = x.body_id;
        j["BodyType"] = x.body_type;
        j["event"] = x.event;
        j["Multicrew"] = x.multicrew;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["Taxi"] = x.taxi;
        j["timestamp"] = x.timestamp;
    }
}


