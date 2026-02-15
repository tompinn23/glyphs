//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     location data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;
    /**
     * When written: at startup, or when being resurrected at a station
     */
    struct location {
        std::string body;
        int64_t body_id;
        std::string body_type;
        std::optional<std::vector<common::conflict>> conflicts;
        /**
         * Controlling power for the system
         */
        std::optional<std::string> controlling_power;
        /**
         * If not close to main star
         */
        std::optional<double> dist_from_star_ls;
        /**
         * True if ship is docked
         */
        bool docked;
        std::string event;
        std::optional<std::vector<common::faction>> factions;
        std::optional<bool> in_srv;
        std::optional<double> latitude;
        std::optional<double> longitude;
        std::optional<int64_t> market_id;
        /**
         * True when inside another player's ship
         */
        std::optional<bool> multicrew;
        std::optional<bool> on_foot;
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
         * Name of starsystem
         */
        std::string star_system;
        std::optional<std::string> station_allegiance;
        /**
         * If starting docked in a station
         */
        std::optional<std::vector<common::station_economy>> station_economies;
        /**
         * If starting docked in a station
         */
        std::optional<std::string> station_economy;
        /**
         * If starting docked in a station
         */
        std::optional<std::string> station_economy_localised;
        /**
         * If starting docked in a station
         */
        std::optional<common::station_faction> station_faction;
        /**
         * If starting docked in a station
         */
        std::optional<std::string> station_government;
        /**
         * If starting docked in a station
         */
        std::optional<std::string> station_government_localised;
        std::optional<std::string> station_name;
        std::optional<std::string> station_name_localised;
        /**
         * If starting docked in a station
         */
        std::optional<std::vector<std::string>> station_services;
        std::optional<std::string> station_type;
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


    void from_json(const json & j, location & x);
    void to_json(json & j, const location & x);

    inline void from_json(const json & j, location& x) {
        x.body = j.at("Body").get<std::string>();
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_type = j.at("BodyType").get<std::string>();
        x.conflicts = get_stack_optional<std::vector<common::conflict>>(j, "Conflicts");
        x.controlling_power = get_stack_optional<std::string>(j, "ControllingPower");
        x.dist_from_star_ls = get_stack_optional<double>(j, "DistFromStarLS");
        x.docked = j.at("Docked").get<bool>();
        x.event = j.at("event").get<std::string>();
        x.factions = get_stack_optional<std::vector<common::faction>>(j, "Factions");
        x.in_srv = get_stack_optional<bool>(j, "InSRV");
        x.latitude = get_stack_optional<double>(j, "Latitude");
        x.longitude = get_stack_optional<double>(j, "Longitude");
        x.market_id = get_stack_optional<int64_t>(j, "MarketID");
        x.multicrew = get_stack_optional<bool>(j, "Multicrew");
        x.on_foot = get_stack_optional<bool>(j, "OnFoot");
        x.population = j.at("Population").get<int64_t>();
        x.powerplay_conflict_progress = get_stack_optional<std::vector<common::powerplay_conflict_progress>>(j, "PowerplayConflictProgress");
        x.powerplay_state = get_stack_optional<std::string>(j, "PowerplayState");
        x.powerplay_state_control_progress = get_stack_optional<double>(j, "PowerplayStateControlProgress");
        x.powerplay_state_reinforcement = get_stack_optional<int64_t>(j, "PowerplayStateReinforcement");
        x.powerplay_state_undermining = get_stack_optional<int64_t>(j, "PowerplayStateUndermining");
        x.powers = get_stack_optional<std::vector<std::string>>(j, "Powers");
        x.star_pos = j.at("StarPos").get<std::vector<double>>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_allegiance = get_stack_optional<std::string>(j, "StationAllegiance");
        x.station_economies = get_stack_optional<std::vector<common::station_economy>>(j, "StationEconomies");
        x.station_economy = get_stack_optional<std::string>(j, "StationEconomy");
        x.station_economy_localised = get_stack_optional<std::string>(j, "StationEconomy_Localised");
        x.station_faction = get_stack_optional<common::station_faction>(j, "StationFaction");
        x.station_government = get_stack_optional<std::string>(j, "StationGovernment");
        x.station_government_localised = get_stack_optional<std::string>(j, "StationGovernment_Localised");
        x.station_name = get_stack_optional<std::string>(j, "StationName");
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_services = get_stack_optional<std::vector<std::string>>(j, "StationServices");
        x.station_type = get_stack_optional<std::string>(j, "StationType");
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

    inline void to_json(json & j, const location & x) {
        j = json::object();
        j["Body"] = x.body;
        j["BodyID"] = x.body_id;
        j["BodyType"] = x.body_type;
        j["Conflicts"] = x.conflicts;
        j["ControllingPower"] = x.controlling_power;
        j["DistFromStarLS"] = x.dist_from_star_ls;
        j["Docked"] = x.docked;
        j["event"] = x.event;
        j["Factions"] = x.factions;
        j["InSRV"] = x.in_srv;
        j["Latitude"] = x.latitude;
        j["Longitude"] = x.longitude;
        j["MarketID"] = x.market_id;
        j["Multicrew"] = x.multicrew;
        j["OnFoot"] = x.on_foot;
        j["Population"] = x.population;
        j["PowerplayConflictProgress"] = x.powerplay_conflict_progress;
        j["PowerplayState"] = x.powerplay_state;
        j["PowerplayStateControlProgress"] = x.powerplay_state_control_progress;
        j["PowerplayStateReinforcement"] = x.powerplay_state_reinforcement;
        j["PowerplayStateUndermining"] = x.powerplay_state_undermining;
        j["Powers"] = x.powers;
        j["StarPos"] = x.star_pos;
        j["StarSystem"] = x.star_system;
        j["StationAllegiance"] = x.station_allegiance;
        j["StationEconomies"] = x.station_economies;
        j["StationEconomy"] = x.station_economy;
        j["StationEconomy_Localised"] = x.station_economy_localised;
        j["StationFaction"] = x.station_faction;
        j["StationGovernment"] = x.station_government;
        j["StationGovernment_Localised"] = x.station_government_localised;
        j["StationName"] = x.station_name;
        j["StationName_Localised"] = x.station_name_localised;
        j["StationServices"] = x.station_services;
        j["StationType"] = x.station_type;
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


