//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     mission_completed data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    namespace types {
        struct commodity_reward {
            int64_t count;
            std::string name;
            /**
             * The localised value will be omitted if it is exactly the same as Name
             */
            std::optional<std::string> name_localised;
        };

        struct effect {
            std::string effect;
            std::optional<std::string> effect_localised;
            std::string trend;
        };

        struct influence {
            std::string influence;
            int64_t system_address;
            std::string trend;
        };

        struct faction_effect {
            std::vector<effect> effects;
            std::string faction;
            std::vector<influence> inf;
            std::string reputation;
            std::string reputation_trend;
        };

        struct materials_reward {
            std::string category;
            std::optional<std::string> category_localised;
            int64_t count;
            std::string name;
            /**
             * The localised value will be omitted if it is exactly the same as Name
             */
            std::optional<std::string> name_localised;
        };
    }

    /**
     * When Written: when a mission is completed
     */
    struct mission_completed {
        std::optional<std::string> commodity;
        std::optional<std::string> commodity_localised;
        /**
         * Names and counts of any commodity rewards
         */
        std::optional<std::vector<types::commodity_reward>> commodity_reward;
        std::optional<int64_t> count;
        std::optional<std::string> destination_settlement;
        std::optional<std::string> destination_station;
        std::optional<std::string> destination_system;
        std::optional<int64_t> donated;
        std::optional<std::string> donation;
        std::string event;
        std::string faction;
        std::optional<std::vector<types::faction_effect>> faction_effects;
        std::optional<int64_t> kill_count;
        std::optional<std::string> localised_name;
        /**
         * Name, category and count of any material rewards
         */
        std::optional<std::vector<types::materials_reward>> materials_reward;
        int64_t mission_id;
        std::string name;
        std::optional<std::string> new_destination_station;
        std::optional<std::string> new_destination_system;
        /**
         * Appears in journal manual, but not in actual events.
         */
        std::optional<std::vector<std::string>> permits_awarded;
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
    };
}

namespace hue {

    namespace types {
            inline void from_json(const json & j, commodity_reward& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const commodity_reward & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, effect& x) {
        x.effect = j.at("Effect").get<std::string>();
        x.effect_localised = get_stack_optional<std::string>(j, "Effect_Localised");
        x.trend = j.at("Trend").get<std::string>();
    }

    inline void to_json(json & j, const effect & x) {
        j = json::object();
        j["Effect"] = x.effect;
        j["Effect_Localised"] = x.effect_localised;
        j["Trend"] = x.trend;
    }

    inline void from_json(const json & j, influence& x) {
        x.influence = j.at("Influence").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.trend = j.at("Trend").get<std::string>();
    }

    inline void to_json(json & j, const influence & x) {
        j = json::object();
        j["Influence"] = x.influence;
        j["SystemAddress"] = x.system_address;
        j["Trend"] = x.trend;
    }

    inline void from_json(const json & j, faction_effect& x) {
        x.effects = j.at("Effects").get<std::vector<effect>>();
        x.faction = j.at("Faction").get<std::string>();
        x.inf = j.at("Influence").get<std::vector<influence>>();
        x.reputation = j.at("Reputation").get<std::string>();
        x.reputation_trend = j.at("ReputationTrend").get<std::string>();
    }

    inline void to_json(json & j, const faction_effect & x) {
        j = json::object();
        j["Effects"] = x.effects;
        j["Faction"] = x.faction;
        j["Influence"] = x.inf;
        j["Reputation"] = x.reputation;
        j["ReputationTrend"] = x.reputation_trend;
    }

    inline void from_json(const json & j, materials_reward& x) {
        x.category = j.at("Category").get<std::string>();
        x.category_localised = get_stack_optional<std::string>(j, "Category_Localised");
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const materials_reward & x) {
        j = json::object();
        j["Category"] = x.category;
        j["Category_Localised"] = x.category_localised;
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }
    }

    inline void from_json(const json & j, mission_completed& x) {
        x.commodity = get_stack_optional<std::string>(j, "Commodity");
        x.commodity_localised = get_stack_optional<std::string>(j, "Commodity_Localised");
        x.commodity_reward = get_stack_optional<std::vector<types::commodity_reward>>(j, "CommodityReward");
        x.count = get_stack_optional<int64_t>(j, "Count");
        x.destination_settlement = get_stack_optional<std::string>(j, "DestinationSettlement");
        x.destination_station = get_stack_optional<std::string>(j, "DestinationStation");
        x.destination_system = get_stack_optional<std::string>(j, "DestinationSystem");
        x.donated = get_stack_optional<int64_t>(j, "Donated");
        x.donation = get_stack_optional<std::string>(j, "Donation");
        x.event = j.at("event").get<std::string>();
        x.faction = j.at("Faction").get<std::string>();
        x.faction_effects = get_stack_optional<std::vector<types::faction_effect>>(j, "FactionEffects");
        x.kill_count = get_stack_optional<int64_t>(j, "KillCount");
        x.localised_name = get_stack_optional<std::string>(j, "LocalisedName");
        x.materials_reward = get_stack_optional<std::vector<types::materials_reward>>(j, "MaterialsReward");
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.new_destination_station = get_stack_optional<std::string>(j, "NewDestinationStation");
        x.new_destination_system = get_stack_optional<std::string>(j, "NewDestinationSystem");
        x.permits_awarded = get_stack_optional<std::vector<std::string>>(j, "PermitsAwarded");
        x.reward = get_stack_optional<int64_t>(j, "Reward");
        x.target = get_stack_optional<std::string>(j, "Target");
        x.target_localised = get_stack_optional<std::string>(j, "Target_Localised");
        x.target_faction = get_stack_optional<std::string>(j, "TargetFaction");
        x.target_type = get_stack_optional<std::string>(j, "TargetType");
        x.target_type_localised = get_stack_optional<std::string>(j, "TargetType_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const mission_completed & x) {
        j = json::object();
        j["Commodity"] = x.commodity;
        j["Commodity_Localised"] = x.commodity_localised;
        j["CommodityReward"] = x.commodity_reward;
        j["Count"] = x.count;
        j["DestinationSettlement"] = x.destination_settlement;
        j["DestinationStation"] = x.destination_station;
        j["DestinationSystem"] = x.destination_system;
        j["Donated"] = x.donated;
        j["Donation"] = x.donation;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["FactionEffects"] = x.faction_effects;
        j["KillCount"] = x.kill_count;
        j["LocalisedName"] = x.localised_name;
        j["MaterialsReward"] = x.materials_reward;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["NewDestinationStation"] = x.new_destination_station;
        j["NewDestinationSystem"] = x.new_destination_system;
        j["PermitsAwarded"] = x.permits_awarded;
        j["Reward"] = x.reward;
        j["Target"] = x.target;
        j["Target_Localised"] = x.target_localised;
        j["TargetFaction"] = x.target_faction;
        j["TargetType"] = x.target_type;
        j["TargetType_Localised"] = x.target_type_localised;
        j["timestamp"] = x.timestamp;
    }
}


