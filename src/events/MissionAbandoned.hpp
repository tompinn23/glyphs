//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     mission_abandoned data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when a mission has been abandoned
     */
    struct mission_abandoned {
        std::string event;
        std::optional<int64_t> fine;
        std::optional<std::string> localised_name;
        int64_t mission_id;
        std::string name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, mission_abandoned & x);
    void to_json(json & j, const mission_abandoned & x);

    inline void from_json(const json & j, mission_abandoned& x) {
        x.event = j.at("event").get<std::string>();
        x.fine = get_stack_optional<int64_t>(j, "Fine");
        x.localised_name = get_stack_optional<std::string>(j, "LocalisedName");
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const mission_abandoned & x) {
        j = json::object();
        j["event"] = x.event;
        j["Fine"] = x.fine;
        j["LocalisedName"] = x.localised_name;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["timestamp"] = x.timestamp;
    }
}


