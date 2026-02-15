//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     bounty data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    struct reward {
        std::string faction;
        int64_t reward;
    };

    /**
     * When written: player is awarded a bounty for a kill
     */
    struct bounty {
        std::string event;
        std::optional<std::string> faction;
        /**
         * Name of the Pilot
         */
        std::optional<std::string> pilot_name;
        /**
         * Name of the Pilot
         */
        std::optional<std::string> pilot_name_localised;
        /**
         * Used instead of Rewards when the bounty is for a skimmer
         */
        std::optional<int64_t> reward;
        /**
         * An array of Faction names and the Reward values, as the target can have multiple bounties
         * payable by different factions. Not used for skimmers.(See Reward)
         */
        std::optional<std::vector<hue::reward>> rewards;
        /**
         * if credit for the kill is shared with other players, this has the number of other players
         * involved
         */
        std::optional<int64_t> shared_with_others;
        /**
         * type of ship
         */
        std::string target;
        std::optional<std::string> target_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Not used for skimmers.
         */
        std::optional<int64_t> total_reward;
        std::string victim_faction;
        std::optional<std::string> victim_faction_localised;
    };
}

namespace hue {
    void from_json(const json & j, reward & x);
    void to_json(json & j, const reward & x);

    void from_json(const json & j, bounty & x);
    void to_json(json & j, const bounty & x);

    inline void from_json(const json & j, reward& x) {
        x.faction = j.at("Faction").get<std::string>();
        x.reward = j.at("Reward").get<int64_t>();
    }

    inline void to_json(json & j, const reward & x) {
        j = json::object();
        j["Faction"] = x.faction;
        j["Reward"] = x.reward;
    }

    inline void from_json(const json & j, bounty& x) {
        x.event = j.at("event").get<std::string>();
        x.faction = get_stack_optional<std::string>(j, "Faction");
        x.pilot_name = get_stack_optional<std::string>(j, "PilotName");
        x.pilot_name_localised = get_stack_optional<std::string>(j, "PilotName_Localised");
        x.reward = get_stack_optional<int64_t>(j, "Reward");
        x.rewards = get_stack_optional<std::vector<reward>>(j, "Rewards");
        x.shared_with_others = get_stack_optional<int64_t>(j, "SharedWithOthers");
        x.target = j.at("Target").get<std::string>();
        x.target_localised = get_stack_optional<std::string>(j, "Target_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_reward = get_stack_optional<int64_t>(j, "TotalReward");
        x.victim_faction = j.at("VictimFaction").get<std::string>();
        x.victim_faction_localised = get_stack_optional<std::string>(j, "VictimFaction_Localised");
    }

    inline void to_json(json & j, const bounty & x) {
        j = json::object();
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["PilotName"] = x.pilot_name;
        j["PilotName_Localised"] = x.pilot_name_localised;
        j["Reward"] = x.reward;
        j["Rewards"] = x.rewards;
        j["SharedWithOthers"] = x.shared_with_others;
        j["Target"] = x.target;
        j["Target_Localised"] = x.target_localised;
        j["timestamp"] = x.timestamp;
        j["TotalReward"] = x.total_reward;
        j["VictimFaction"] = x.victim_faction;
        j["VictimFaction_Localised"] = x.victim_faction_localised;
    }
}


