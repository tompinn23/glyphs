//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     liftoff data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when taking off from planet surface
     */
    struct liftoff {
        std::optional<std::string> body;
        std::optional<int64_t> body_id;
        std::string event;
        /**
         * only if player flying in ship)
         */
        std::optional<double> latitude;
        /**
         * only if player flying in ship)
         */
        std::optional<double> longitude;
        std::optional<bool> multicrew;
        std::optional<std::string> nearest_destination;
        std::optional<std::string> nearest_destination_localised;
        std::optional<bool> on_planet;
        std::optional<bool> on_station;
        /**
         * false if ship dismissed when player is in SRV, true if player is taking off
         */
        bool player_controlled;
        std::optional<std::string> star_system;
        std::optional<int64_t> system_address;
        std::optional<bool> taxi;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, liftoff & x);
    void to_json(json & j, const liftoff & x);

    inline void from_json(const json & j, liftoff& x) {
        x.body = get_stack_optional<std::string>(j, "Body");
        x.body_id = get_stack_optional<int64_t>(j, "BodyID");
        x.event = j.at("event").get<std::string>();
        x.latitude = get_stack_optional<double>(j, "Latitude");
        x.longitude = get_stack_optional<double>(j, "Longitude");
        x.multicrew = get_stack_optional<bool>(j, "Multicrew");
        x.nearest_destination = get_stack_optional<std::string>(j, "NearestDestination");
        x.nearest_destination_localised = get_stack_optional<std::string>(j, "NearestDestination_Localised");
        x.on_planet = get_stack_optional<bool>(j, "OnPlanet");
        x.on_station = get_stack_optional<bool>(j, "OnStation");
        x.player_controlled = j.at("PlayerControlled").get<bool>();
        x.star_system = get_stack_optional<std::string>(j, "StarSystem");
        x.system_address = get_stack_optional<int64_t>(j, "SystemAddress");
        x.taxi = get_stack_optional<bool>(j, "Taxi");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const liftoff & x) {
        j = json::object();
        j["Body"] = x.body;
        j["BodyID"] = x.body_id;
        j["event"] = x.event;
        j["Latitude"] = x.latitude;
        j["Longitude"] = x.longitude;
        j["Multicrew"] = x.multicrew;
        j["NearestDestination"] = x.nearest_destination;
        j["NearestDestination_Localised"] = x.nearest_destination_localised;
        j["OnPlanet"] = x.on_planet;
        j["OnStation"] = x.on_station;
        j["PlayerControlled"] = x.player_controlled;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["Taxi"] = x.taxi;
        j["timestamp"] = x.timestamp;
    }
}


