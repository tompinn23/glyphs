//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ship_targeted data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when the current player selects a new target
     */
    struct ship_targeted {
        /**
         * If Scan stage >= 3
         */
        std::optional<int64_t> bounty;
        std::string event;
        /**
         * If Scan stage >= 3
         */
        std::optional<std::string> faction;
        /**
         * If Scan stage >= 2
         */
        std::optional<double> hull_health;
        /**
         * If Scan stage >= 3
         */
        std::optional<std::string> legal_status;
        /**
         * If Scan stage >= 1
         */
        std::optional<std::string> pilot_name;
        /**
         * If Scan stage >= 1
         */
        std::optional<std::string> pilot_name_localised;
        /**
         * If Scan stage >= 1
         */
        std::optional<std::string> pilot_rank;
        /**
         * If the player is aligned in powerplay and the target is also aligned to a power
         */
        std::optional<std::string> power;
        std::optional<int64_t> scan_stage;
        /**
         * If Scan stage >= 2
         */
        std::optional<double> shield_health;
        std::optional<std::string> ship;
        /**
         * If target locked
         */
        std::optional<std::string> ship_localised;
        /**
         * If target in a squadron
         */
        std::optional<std::string> squadron_id;
        /**
         * If Scan stage >= 3
         */
        std::optional<std::string> subsystem;
        /**
         * If Scan stage >= 3
         */
        std::optional<std::string> subsystem_localised;
        /**
         * If Scan stage >= 3
         */
        std::optional<double> subsystem_health;
        bool target_locked;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, ship_targeted & x);
    void to_json(json & j, const ship_targeted & x);

    inline void from_json(const json & j, ship_targeted& x) {
        x.bounty = get_stack_optional<int64_t>(j, "Bounty");
        x.event = j.at("event").get<std::string>();
        x.faction = get_stack_optional<std::string>(j, "Faction");
        x.hull_health = get_stack_optional<double>(j, "HullHealth");
        x.legal_status = get_stack_optional<std::string>(j, "LegalStatus");
        x.pilot_name = get_stack_optional<std::string>(j, "PilotName");
        x.pilot_name_localised = get_stack_optional<std::string>(j, "PilotName_Localised");
        x.pilot_rank = get_stack_optional<std::string>(j, "PilotRank");
        x.power = get_stack_optional<std::string>(j, "Power");
        x.scan_stage = get_stack_optional<int64_t>(j, "ScanStage");
        x.shield_health = get_stack_optional<double>(j, "ShieldHealth");
        x.ship = get_stack_optional<std::string>(j, "Ship");
        x.ship_localised = get_stack_optional<std::string>(j, "Ship_Localised");
        x.squadron_id = get_stack_optional<std::string>(j, "SquadronID");
        x.subsystem = get_stack_optional<std::string>(j, "Subsystem");
        x.subsystem_localised = get_stack_optional<std::string>(j, "Subsystem_Localised");
        x.subsystem_health = get_stack_optional<double>(j, "SubsystemHealth");
        x.target_locked = j.at("TargetLocked").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const ship_targeted & x) {
        j = json::object();
        j["Bounty"] = x.bounty;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["HullHealth"] = x.hull_health;
        j["LegalStatus"] = x.legal_status;
        j["PilotName"] = x.pilot_name;
        j["PilotName_Localised"] = x.pilot_name_localised;
        j["PilotRank"] = x.pilot_rank;
        j["Power"] = x.power;
        j["ScanStage"] = x.scan_stage;
        j["ShieldHealth"] = x.shield_health;
        j["Ship"] = x.ship;
        j["Ship_Localised"] = x.ship_localised;
        j["SquadronID"] = x.squadron_id;
        j["Subsystem"] = x.subsystem;
        j["Subsystem_Localised"] = x.subsystem_localised;
        j["SubsystemHealth"] = x.subsystem_health;
        j["TargetLocked"] = x.target_locked;
        j["timestamp"] = x.timestamp;
    }
}


