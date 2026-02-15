//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     approach_settlement data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"

namespace hue {
    /**
     * When written: when approaching a planetary settlement
     */
    struct approach_settlement {
        int64_t body_id;
        std::string body_name;
        std::string event;
        std::optional<double> latitude;
        std::optional<double> longitude;
        std::optional<int64_t> market_id;
        std::string name;
        std::optional<std::string> name_localised;
        std::optional<std::string> station_allegiance;
        std::optional<std::vector<common::station_economy>> station_economies;
        std::optional<std::string> station_economy;
        std::optional<std::string> station_economy_localised;
        std::optional<common::station_faction> station_faction;
        std::optional<std::string> station_government;
        std::optional<std::string> station_government_localised;
        std::optional<std::vector<std::string>> station_services;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {

    void from_json(const json & j, approach_settlement & x);
    void to_json(json & j, const approach_settlement & x);


    inline void from_json(const json & j, approach_settlement& x) {
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_name = j.at("BodyName").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.latitude = get_stack_optional<double>(j, "Latitude");
        x.longitude = get_stack_optional<double>(j, "Longitude");
        x.market_id = get_stack_optional<int64_t>(j, "MarketID");
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.station_allegiance = get_stack_optional<std::string>(j, "StationAllegiance");
        x.station_economies = get_stack_optional<std::vector<common::station_economy>>(j, "StationEconomies");
        x.station_economy = get_stack_optional<std::string>(j, "StationEconomy");
        x.station_economy_localised = get_stack_optional<std::string>(j, "StationEconomy_Localised");
        x.station_faction = get_stack_optional<common::station_faction>(j, "StationFaction");
        x.station_government = get_stack_optional<std::string>(j, "StationGovernment");
        x.station_government_localised = get_stack_optional<std::string>(j, "StationGovernment_Localised");
        x.station_services = get_stack_optional<std::vector<std::string>>(j, "StationServices");
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const approach_settlement & x) {
        j = json::object();
        j["BodyID"] = x.body_id;
        j["BodyName"] = x.body_name;
        j["event"] = x.event;
        j["Latitude"] = x.latitude;
        j["Longitude"] = x.longitude;
        j["MarketID"] = x.market_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["StationAllegiance"] = x.station_allegiance;
        j["StationEconomies"] = x.station_economies;
        j["StationEconomy"] = x.station_economy;
        j["StationEconomy_Localised"] = x.station_economy_localised;
        j["StationFaction"] = x.station_faction;
        j["StationGovernment"] = x.station_government;
        j["StationGovernment_Localised"] = x.station_government_localised;
        j["StationServices"] = x.station_services;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


