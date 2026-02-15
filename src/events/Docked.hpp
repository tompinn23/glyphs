//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     docked data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when landing at landing pad in a space station, outpost, or surface
     * settlement
     */
    struct docked {
        /**
         * Only if any fine is active
         */
        std::optional<bool> active_fine;
        /**
         * true (only if landing with breached cockpit)
         */
        std::optional<bool> cockpit_breach;
        double dist_from_star_ls;
        std::string event;
        std::optional<common::landing_pads> landing_pads;
        int64_t market_id;
        std::optional<bool> multicrew;
        std::string star_system;
        std::optional<std::string> station_allegiance;
        /**
         * Only if station has multiple economies
         */
        std::optional<std::vector<common::station_economy>> station_economies;
        /**
         * Only if station has a single economy
         */
        std::optional<std::string> station_economy;
        /**
         * Only if station has a single economy
         */
        std::optional<std::string> station_economy_localised;
        std::optional<common::station_faction> station_faction;
        std::string station_government;
        std::optional<std::string> station_government_localised;
        std::string station_name;
        std::optional<std::string> station_name_localised;
        /**
         * StationServices can include: Dock, Autodock, BlackMarket, Commodities, Contacts,
         * Exploration, Initiatives, Missions, Outfitting, CrewLounge, Rearm, Refuel, Repair,
         * Shipyard, Tuning, Workshop, MissionsGenerated, Facilitator, Research, FlightController,
         * StationOperations, OnDockMission, Powerplay, SearchAndRescue. New in v3.7: shop,
         * carriermanagement, carrierfuel, carriervendor, livery, modulepacks, voucherredemption
         */
        std::vector<std::string> station_services;
        std::optional<std::string> station_state;
        std::string station_type;
        int64_t system_address;
        std::optional<bool> taxi;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Only if docking when wanted locally
         */
        std::optional<bool> wanted;
    };
}

namespace hue {

    void from_json(const json & j, docked & x);
    void to_json(json & j, const docked & x);

    inline void from_json(const json & j, docked& x) {
        x.active_fine = get_stack_optional<bool>(j, "ActiveFine");
        x.cockpit_breach = get_stack_optional<bool>(j, "CockpitBreach");
        x.dist_from_star_ls = j.at("DistFromStarLS").get<double>();
        x.event = j.at("event").get<std::string>();
        x.landing_pads = get_stack_optional<common::landing_pads>(j, "LandingPads");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.multicrew = get_stack_optional<bool>(j, "Multicrew");
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_allegiance = get_stack_optional<std::string>(j, "StationAllegiance");
        x.station_economies = get_stack_optional<std::vector<common::station_economy>>(j, "StationEconomies");
        x.station_economy = get_stack_optional<std::string>(j, "StationEconomy");
        x.station_economy_localised = get_stack_optional<std::string>(j, "StationEconomy_Localised");
        x.station_faction = get_stack_optional<common::station_faction>(j, "StationFaction");
        x.station_government = j.at("StationGovernment").get<std::string>();
        x.station_government_localised = get_stack_optional<std::string>(j, "StationGovernment_Localised");
        x.station_name = j.at("StationName").get<std::string>();
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_services = j.at("StationServices").get<std::vector<std::string>>();
        x.station_state = get_stack_optional<std::string>(j, "StationState");
        x.station_type = j.at("StationType").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.taxi = get_stack_optional<bool>(j, "Taxi");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.wanted = get_stack_optional<bool>(j, "Wanted");
    }

    inline void to_json(json & j, const docked & x) {
        j = json::object();
        j["ActiveFine"] = x.active_fine;
        j["CockpitBreach"] = x.cockpit_breach;
        j["DistFromStarLS"] = x.dist_from_star_ls;
        j["event"] = x.event;
        j["LandingPads"] = x.landing_pads;
        j["MarketID"] = x.market_id;
        j["Multicrew"] = x.multicrew;
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
        j["StationState"] = x.station_state;
        j["StationType"] = x.station_type;
        j["SystemAddress"] = x.system_address;
        j["Taxi"] = x.taxi;
        j["timestamp"] = x.timestamp;
        j["Wanted"] = x.wanted;
    }
}


