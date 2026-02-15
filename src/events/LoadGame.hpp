//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     load_game data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct load_game {
        std::optional<std::string> build;
        std::string commander;
        /**
         * Current credit balance
         */
        int64_t credits;
        std::string event;
        std::string fid;
        /**
         * Size of main tank
         */
        std::optional<double> fuel_capacity;
        /**
         * Current fuel level
         */
        std::optional<double> fuel_level;
        /**
         * Open, Solo or Group
         */
        std::optional<std::string> game_mode;
        std::optional<std::string> gameversion;
        /**
         * name of group (if in a group session)
         */
        std::optional<std::string> group;
        /**
         * Whether Game has Horizons enabled.
         */
        bool horizons;
        std::optional<std::string> language;
        /**
         * Current loan
         */
        int64_t loan;
        /**
         * Whether Game has Odyssey enabled. Only present if in Odyssey game mode
         */
        std::optional<bool> odyssey;
        std::optional<std::string> ship;
        std::optional<std::string> ship_localised;
        std::optional<int64_t> ship_id;
        /**
         * User-defined ship ID string
         */
        std::optional<std::string> ship_ident;
        /**
         * User-defined ship name
         */
        std::optional<std::string> ship_name;
        /**
         * only present if starting dead: see Resurrect
         */
        std::optional<bool> start_dead;
        /**
         * Only present if landed
         */
        std::optional<bool> start_landed;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, load_game & x);
    void to_json(json & j, const load_game & x);

    inline void from_json(const json & j, load_game& x) {
        x.build = get_stack_optional<std::string>(j, "build");
        x.commander = j.at("Commander").get<std::string>();
        x.credits = j.at("Credits").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.fid = j.at("FID").get<std::string>();
        x.fuel_capacity = get_stack_optional<double>(j, "FuelCapacity");
        x.fuel_level = get_stack_optional<double>(j, "FuelLevel");
        x.game_mode = get_stack_optional<std::string>(j, "GameMode");
        x.gameversion = get_stack_optional<std::string>(j, "gameversion");
        x.group = get_stack_optional<std::string>(j, "Group");
        x.horizons = j.at("Horizons").get<bool>();
        x.language = get_stack_optional<std::string>(j, "language");
        x.loan = j.at("Loan").get<int64_t>();
        x.odyssey = get_stack_optional<bool>(j, "Odyssey");
        x.ship = get_stack_optional<std::string>(j, "Ship");
        x.ship_localised = get_stack_optional<std::string>(j, "Ship_Localised");
        x.ship_id = get_stack_optional<int64_t>(j, "ShipID");
        x.ship_ident = get_stack_optional<std::string>(j, "ShipIdent");
        x.ship_name = get_stack_optional<std::string>(j, "ShipName");
        x.start_dead = get_stack_optional<bool>(j, "StartDead");
        x.start_landed = get_stack_optional<bool>(j, "StartLanded");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const load_game & x) {
        j = json::object();
        j["build"] = x.build;
        j["Commander"] = x.commander;
        j["Credits"] = x.credits;
        j["event"] = x.event;
        j["FID"] = x.fid;
        j["FuelCapacity"] = x.fuel_capacity;
        j["FuelLevel"] = x.fuel_level;
        j["GameMode"] = x.game_mode;
        j["gameversion"] = x.gameversion;
        j["Group"] = x.group;
        j["Horizons"] = x.horizons;
        j["language"] = x.language;
        j["Loan"] = x.loan;
        j["Odyssey"] = x.odyssey;
        j["Ship"] = x.ship;
        j["Ship_Localised"] = x.ship_localised;
        j["ShipID"] = x.ship_id;
        j["ShipIdent"] = x.ship_ident;
        j["ShipName"] = x.ship_name;
        j["StartDead"] = x.start_dead;
        j["StartLanded"] = x.start_landed;
        j["timestamp"] = x.timestamp;
    }
}


