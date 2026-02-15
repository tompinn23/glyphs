//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     mission_accepted data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when starting a mission
     */
    struct mission_accepted {
        std::optional<std::string> commodity;
        std::optional<std::string> commodity_localised;
        /**
         * Number required to deliver
         */
        std::optional<int64_t> count;
        std::optional<std::string> destination_settlement;
        std::optional<std::string> destination_station;
        std::optional<std::string> destination_system;
        std::optional<std::string> donation;
        std::string event;
        /**
         * Mission expiry time, in ISO 8601
         */
        std::optional<std::string> expiry;
        /**
         * Faction offering mission
         */
        std::string faction;
        std::string influence;
        /**
         * Number of targets
         */
        std::optional<int64_t> kill_count;
        std::string localised_name;
        int64_t mission_id;
        std::string name;
        /**
         * If it has been redirected
         */
        std::optional<std::string> new_destination_station;
        /**
         * If it has been redirected
         */
        std::optional<std::string> new_destination_system;
        std::optional<int64_t> passenger_count;
        std::optional<std::string> passenger_type;
        std::optional<bool> passenger_vi_ps;
        std::optional<bool> passenger_wanted;
        std::string reputation;
        std::optional<int64_t> reward;
        std::optional<std::string> target;
        std::optional<std::string> target_localised;
        std::optional<std::string> target_faction;
        std::optional<std::string> target_type;
        std::optional<std::string> target_type_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        bool wing;
    };
}

namespace hue {
    void from_json(const json & j, mission_accepted & x);
    void to_json(json & j, const mission_accepted & x);

    inline void from_json(const json & j, mission_accepted& x) {
        x.commodity = get_stack_optional<std::string>(j, "Commodity");
        x.commodity_localised = get_stack_optional<std::string>(j, "Commodity_Localised");
        x.count = get_stack_optional<int64_t>(j, "Count");
        x.destination_settlement = get_stack_optional<std::string>(j, "DestinationSettlement");
        x.destination_station = get_stack_optional<std::string>(j, "DestinationStation");
        x.destination_system = get_stack_optional<std::string>(j, "DestinationSystem");
        x.donation = get_stack_optional<std::string>(j, "Donation");
        x.event = j.at("event").get<std::string>();
        x.expiry = get_stack_optional<std::string>(j, "Expiry");
        x.faction = j.at("Faction").get<std::string>();
        x.influence = j.at("Influence").get<std::string>();
        x.kill_count = get_stack_optional<int64_t>(j, "KillCount");
        x.localised_name = j.at("LocalisedName").get<std::string>();
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.new_destination_station = get_stack_optional<std::string>(j, "NewDestinationStation");
        x.new_destination_system = get_stack_optional<std::string>(j, "NewDestinationSystem");
        x.passenger_count = get_stack_optional<int64_t>(j, "PassengerCount");
        x.passenger_type = get_stack_optional<std::string>(j, "PassengerType");
        x.passenger_vi_ps = get_stack_optional<bool>(j, "PassengerVIPs");
        x.passenger_wanted = get_stack_optional<bool>(j, "PassengerWanted");
        x.reputation = j.at("Reputation").get<std::string>();
        x.reward = get_stack_optional<int64_t>(j, "Reward");
        x.target = get_stack_optional<std::string>(j, "Target");
        x.target_localised = get_stack_optional<std::string>(j, "Target_Localised");
        x.target_faction = get_stack_optional<std::string>(j, "TargetFaction");
        x.target_type = get_stack_optional<std::string>(j, "TargetType");
        x.target_type_localised = get_stack_optional<std::string>(j, "TargetType_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.wing = j.at("Wing").get<bool>();
    }

    inline void to_json(json & j, const mission_accepted & x) {
        j = json::object();
        j["Commodity"] = x.commodity;
        j["Commodity_Localised"] = x.commodity_localised;
        j["Count"] = x.count;
        j["DestinationSettlement"] = x.destination_settlement;
        j["DestinationStation"] = x.destination_station;
        j["DestinationSystem"] = x.destination_system;
        j["Donation"] = x.donation;
        j["event"] = x.event;
        j["Expiry"] = x.expiry;
        j["Faction"] = x.faction;
        j["Influence"] = x.influence;
        j["KillCount"] = x.kill_count;
        j["LocalisedName"] = x.localised_name;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["NewDestinationStation"] = x.new_destination_station;
        j["NewDestinationSystem"] = x.new_destination_system;
        j["PassengerCount"] = x.passenger_count;
        j["PassengerType"] = x.passenger_type;
        j["PassengerVIPs"] = x.passenger_vi_ps;
        j["PassengerWanted"] = x.passenger_wanted;
        j["Reputation"] = x.reputation;
        j["Reward"] = x.reward;
        j["Target"] = x.target;
        j["Target_Localised"] = x.target_localised;
        j["TargetFaction"] = x.target_faction;
        j["TargetType"] = x.target_type;
        j["TargetType_Localised"] = x.target_type_localised;
        j["timestamp"] = x.timestamp;
        j["Wing"] = x.wing;
    }
}


