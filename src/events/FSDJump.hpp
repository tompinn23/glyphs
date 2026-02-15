//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fsd_jump data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    /**
     * When written: when jumping from one star system to another
     */
    struct fsd_jump {
        std::string body;
        int64_t body_id;
        std::string body_type;
        /**
         * Whether FSD boost was used
         */
        std::optional<int64_t> boost_used;
        std::optional<std::vector<common::conflict>> conflicts;
        /**
         * Controlling power for the system
         */
        std::optional<std::string> controlling_power;
        std::string event;
        std::optional<std::vector<common::faction>> factions;
        double fuel_level;
        double fuel_used;
        /**
         * Distance jumped
         */
        double jump_dist;
        /**
         * True when inside another player's ship
         */
        std::optional<bool> multicrew;
        int64_t population;
        /**
         * When the system is unoccupied and 1 or more powers are fighting for control by reaching
         * 120k merits.
         */
        std::optional<std::vector<common::powerplay_conflict_progress>> powerplay_conflict_progress;
        /**
         * Powerplay state for the system.
         */
        std::optional<std::string> powerplay_state;
        /**
         * The current amount of control within the specific powerplay state
         */
        std::optional<double> powerplay_state_control_progress;
        /**
         * Merits gained towards reinforcing the system and increasing the system strength
         */
        std::optional<int64_t> powerplay_state_reinforcement;
        /**
         * Merits gained towards undermining the system and decreasing the system strength
         */
        std::optional<int64_t> powerplay_state_undermining;
        /**
         * If the player is pledged to a Power in Powerplay, and the star system is involved in
         * powerplay
         */
        std::optional<std::vector<std::string>> powers;
        /**
         * star position, as a Json array [x, y, z], relative to Sol in Ly
         */
        std::vector<double> star_pos;
        /**
         * Name of destination starsystem
         */
        std::string star_system;
        int64_t system_address;
        std::string system_allegiance;
        std::string system_economy;
        std::optional<std::string> system_economy_localised;
        /**
         * System controlling faction
         */
        std::optional<common::system_faction> system_faction;
        std::string system_government;
        std::optional<std::string> system_government_localised;
        std::string system_second_economy;
        std::optional<std::string> system_second_economy_localised;
        std::string system_security;
        std::optional<std::string> system_security_localised;
        /**
         * True when inside a taxi transport ship
         */
        std::optional<bool> taxi;
        /**
         * Thargoid war information
         */
        std::optional<common::thargoid_war> thargoid_war;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<bool> wanted;
    };
}

namespace hue {

    void from_json(const json & j, fsd_jump & x);
    void to_json(json & j, const fsd_jump & x);

    inline void from_json(const json & j, fsd_jump& x) {
        x.body = j.at("Body").get<std::string>();
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_type = j.at("BodyType").get<std::string>();
        x.boost_used = get_stack_optional<int64_t>(j, "BoostUsed");
        x.conflicts = get_stack_optional<std::vector<common::conflict>>(j, "Conflicts");
        x.controlling_power = get_stack_optional<std::string>(j, "ControllingPower");
        x.event = j.at("event").get<std::string>();
        x.factions = get_stack_optional<std::vector<common::faction>>(j, "Factions");
        x.fuel_level = j.at("FuelLevel").get<double>();
        x.fuel_used = j.at("FuelUsed").get<double>();
        x.jump_dist = j.at("JumpDist").get<double>();
        x.multicrew = get_stack_optional<bool>(j, "Multicrew");
        x.population = j.at("Population").get<int64_t>();
        x.powerplay_conflict_progress = get_stack_optional<std::vector<common::powerplay_conflict_progress>>(j, "PowerplayConflictProgress");
        x.powerplay_state = get_stack_optional<std::string>(j, "PowerplayState");
        x.powerplay_state_control_progress = get_stack_optional<double>(j, "PowerplayStateControlProgress");
        x.powerplay_state_reinforcement = get_stack_optional<int64_t>(j, "PowerplayStateReinforcement");
        x.powerplay_state_undermining = get_stack_optional<int64_t>(j, "PowerplayStateUndermining");
        x.powers = get_stack_optional<std::vector<std::string>>(j, "Powers");
        x.star_pos = j.at("StarPos").get<std::vector<double>>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.system_allegiance = j.at("SystemAllegiance").get<std::string>();
        x.system_economy = j.at("SystemEconomy").get<std::string>();
        x.system_economy_localised = get_stack_optional<std::string>(j, "SystemEconomy_Localised");
        x.system_faction = get_stack_optional<common::system_faction>(j, "SystemFaction");
        x.system_government = j.at("SystemGovernment").get<std::string>();
        x.system_government_localised = get_stack_optional<std::string>(j, "SystemGovernment_Localised");
        x.system_second_economy = j.at("SystemSecondEconomy").get<std::string>();
        x.system_second_economy_localised = get_stack_optional<std::string>(j, "SystemSecondEconomy_Localised");
        x.system_security = j.at("SystemSecurity").get<std::string>();
        x.system_security_localised = get_stack_optional<std::string>(j, "SystemSecurity_Localised");
        x.taxi = get_stack_optional<bool>(j, "Taxi");
        x.thargoid_war = get_stack_optional<common::thargoid_war>(j, "ThargoidWar");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.wanted = get_stack_optional<bool>(j, "Wanted");
    }

    inline void to_json(json & j, const fsd_jump & x) {
        j = json::object();
        j["Body"] = x.body;
        j["BodyID"] = x.body_id;
        j["BodyType"] = x.body_type;
        j["BoostUsed"] = x.boost_used;
        j["Conflicts"] = x.conflicts;
        j["ControllingPower"] = x.controlling_power;
        j["event"] = x.event;
        j["Factions"] = x.factions;
        j["FuelLevel"] = x.fuel_level;
        j["FuelUsed"] = x.fuel_used;
        j["JumpDist"] = x.jump_dist;
        j["Multicrew"] = x.multicrew;
        j["Population"] = x.population;
        j["PowerplayConflictProgress"] = x.powerplay_conflict_progress;
        j["PowerplayState"] = x.powerplay_state;
        j["PowerplayStateControlProgress"] = x.powerplay_state_control_progress;
        j["PowerplayStateReinforcement"] = x.powerplay_state_reinforcement;
        j["PowerplayStateUndermining"] = x.powerplay_state_undermining;
        j["Powers"] = x.powers;
        j["StarPos"] = x.star_pos;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["SystemAllegiance"] = x.system_allegiance;
        j["SystemEconomy"] = x.system_economy;
        j["SystemEconomy_Localised"] = x.system_economy_localised;
        j["SystemFaction"] = x.system_faction;
        j["SystemGovernment"] = x.system_government;
        j["SystemGovernment_Localised"] = x.system_government_localised;
        j["SystemSecondEconomy"] = x.system_second_economy;
        j["SystemSecondEconomy_Localised"] = x.system_second_economy_localised;
        j["SystemSecurity"] = x.system_security;
        j["SystemSecurity_Localised"] = x.system_security_localised;
        j["Taxi"] = x.taxi;
        j["ThargoidWar"] = x.thargoid_war;
        j["timestamp"] = x.timestamp;
        j["Wanted"] = x.wanted;
    }
}


