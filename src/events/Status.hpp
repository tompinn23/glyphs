//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     status data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    namespace types {

    struct destination {
        int64_t body;
        std::string name;
        std::optional<std::string> name_localised;
        int64_t system;
    };

    struct fuel {
        double fuel_main;
        double fuel_reservoir;
    };
}

    /**
     * This event is written to Status.json which is updated every few seconds
     */
    struct status {
        std::optional<int64_t> altitude;
        std::optional<int64_t> balance;
        std::optional<std::string> body_name;
        std::optional<double> cargo;
        std::optional<types::destination> destination;
        std::string event;
        std::optional<int64_t> fire_group;
        int64_t flags;
        std::optional<int64_t> flags2;
        std::optional<types::fuel> fuel;
        std::optional<double> gravity;
        std::optional<int64_t> gui_focus;
        std::optional<int64_t> heading;
        std::optional<double> health;
        std::optional<double> latitude;
        std::optional<std::string> legal_state;
        std::optional<double> longitude;
        std::optional<double> oxygen;
        std::optional<std::vector<int64_t>> pips;
        std::optional<double> planet_radius;
        std::optional<std::string> selected_weapon;
        std::optional<std::string> selected_weapon_localised;
        std::optional<double> temperature;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    namespace types {

    inline void from_json(const json & j, destination& x) {
        x.body = j.at("Body").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.system = j.at("System").get<int64_t>();
    }

    inline void to_json(json & j, const destination & x) {
        j = json::object();
        j["Body"] = x.body;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["System"] = x.system;
    }

    inline void from_json(const json & j, fuel& x) {
        x.fuel_main = j.at("FuelMain").get<double>();
        x.fuel_reservoir = j.at("FuelReservoir").get<double>();
    }

    inline void to_json(json & j, const fuel & x) {
        j = json::object();
        j["FuelMain"] = x.fuel_main;
        j["FuelReservoir"] = x.fuel_reservoir;
    }
}

    inline void from_json(const json & j, status& x) {
        x.altitude = get_stack_optional<int64_t>(j, "Altitude");
        x.balance = get_stack_optional<int64_t>(j, "Balance");
        x.body_name = get_stack_optional<std::string>(j, "BodyName");
        x.cargo = get_stack_optional<double>(j, "Cargo");
        x.destination = get_stack_optional<types::destination>(j, "Destination");
        x.event = j.at("event").get<std::string>();
        x.fire_group = get_stack_optional<int64_t>(j, "FireGroup");
        x.flags = j.at("Flags").get<int64_t>();
        x.flags2 = get_stack_optional<int64_t>(j, "Flags2");
        x.fuel = get_stack_optional<types::fuel>(j, "Fuel");
        x.gravity = get_stack_optional<double>(j, "Gravity");
        x.gui_focus = get_stack_optional<int64_t>(j, "GuiFocus");
        x.heading = get_stack_optional<int64_t>(j, "Heading");
        x.health = get_stack_optional<double>(j, "Health");
        x.latitude = get_stack_optional<double>(j, "Latitude");
        x.legal_state = get_stack_optional<std::string>(j, "LegalState");
        x.longitude = get_stack_optional<double>(j, "Longitude");
        x.oxygen = get_stack_optional<double>(j, "Oxygen");
        x.pips = get_stack_optional<std::vector<int64_t>>(j, "Pips");
        x.planet_radius = get_stack_optional<double>(j, "PlanetRadius");
        x.selected_weapon = get_stack_optional<std::string>(j, "SelectedWeapon");
        x.selected_weapon_localised = get_stack_optional<std::string>(j, "SelectedWeapon_Localised");
        x.temperature = get_stack_optional<double>(j, "Temperature");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const status & x) {
        j = json::object();
        j["Altitude"] = x.altitude;
        j["Balance"] = x.balance;
        j["BodyName"] = x.body_name;
        j["Cargo"] = x.cargo;
        j["Destination"] = x.destination;
        j["event"] = x.event;
        j["FireGroup"] = x.fire_group;
        j["Flags"] = x.flags;
        j["Flags2"] = x.flags2;
        j["Fuel"] = x.fuel;
        j["Gravity"] = x.gravity;
        j["GuiFocus"] = x.gui_focus;
        j["Heading"] = x.heading;
        j["Health"] = x.health;
        j["Latitude"] = x.latitude;
        j["LegalState"] = x.legal_state;
        j["Longitude"] = x.longitude;
        j["Oxygen"] = x.oxygen;
        j["Pips"] = x.pips;
        j["PlanetRadius"] = x.planet_radius;
        j["SelectedWeapon"] = x.selected_weapon;
        j["SelectedWeapon_Localised"] = x.selected_weapon_localised;
        j["Temperature"] = x.temperature;
        j["timestamp"] = x.timestamp;
    }
}


