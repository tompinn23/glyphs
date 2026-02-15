//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     mission_redirected data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when a mission is updated with a new destination
     */
    struct mission_redirected {
        std::string event;
        std::optional<std::string> localised_name;
        std::optional<std::string> localised_name_localised;
        int64_t mission_id;
        std::string name;
        std::string new_destination_station;
        std::string new_destination_system;
        std::string old_destination_station;
        std::string old_destination_system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, mission_redirected & x);
    void to_json(json & j, const mission_redirected & x);

    inline void from_json(const json & j, mission_redirected& x) {
        x.event = j.at("event").get<std::string>();
        x.localised_name = get_stack_optional<std::string>(j, "LocalisedName");
        x.localised_name_localised = get_stack_optional<std::string>(j, "LocalisedName_Localised");
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.new_destination_station = j.at("NewDestinationStation").get<std::string>();
        x.new_destination_system = j.at("NewDestinationSystem").get<std::string>();
        x.old_destination_station = j.at("OldDestinationStation").get<std::string>();
        x.old_destination_system = j.at("OldDestinationSystem").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const mission_redirected & x) {
        j = json::object();
        j["event"] = x.event;
        j["LocalisedName"] = x.localised_name;
        j["LocalisedName_Localised"] = x.localised_name_localised;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["NewDestinationStation"] = x.new_destination_station;
        j["NewDestinationSystem"] = x.new_destination_system;
        j["OldDestinationStation"] = x.old_destination_station;
        j["OldDestinationSystem"] = x.old_destination_system;
        j["timestamp"] = x.timestamp;
    }
}


