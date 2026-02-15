//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     disembark data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * This event is logged when the player steps out of a ship or SRV
     */
    struct disembark {
        std::string body;
        int64_t body_id;
        std::string event;
        /**
         * playerΓÇÖs ship ID (if players own vessel)
         */
        std::optional<int64_t> id;
        std::optional<int64_t> market_id;
        /**
         * true when getting out of another playerΓÇÖs vessel
         */
        bool multicrew;
        bool on_planet;
        bool on_station;
        /**
         * true if getting out of SRV, false if getting out of a ship
         */
        bool srv;
        std::string star_system;
        /**
         * If at a station
         */
        std::optional<std::string> station_name;
        /**
         * If at a station
         */
        std::optional<std::string> station_type;
        int64_t system_address;
        /**
         * true when getting out of a taxi transposrt ship
         */
        bool taxi;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, disembark & x);
    void to_json(json & j, const disembark & x);

    inline void from_json(const json & j, disembark& x) {
        x.body = j.at("Body").get<std::string>();
        x.body_id = j.at("BodyID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.id = get_stack_optional<int64_t>(j, "ID");
        x.market_id = get_stack_optional<int64_t>(j, "MarketID");
        x.multicrew = j.at("Multicrew").get<bool>();
        x.on_planet = j.at("OnPlanet").get<bool>();
        x.on_station = j.at("OnStation").get<bool>();
        x.srv = j.at("SRV").get<bool>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_name = get_stack_optional<std::string>(j, "StationName");
        x.station_type = get_stack_optional<std::string>(j, "StationType");
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.taxi = j.at("Taxi").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const disembark & x) {
        j = json::object();
        j["Body"] = x.body;
        j["BodyID"] = x.body_id;
        j["event"] = x.event;
        j["ID"] = x.id;
        j["MarketID"] = x.market_id;
        j["Multicrew"] = x.multicrew;
        j["OnPlanet"] = x.on_planet;
        j["OnStation"] = x.on_station;
        j["SRV"] = x.srv;
        j["StarSystem"] = x.star_system;
        j["StationName"] = x.station_name;
        j["StationType"] = x.station_type;
        j["SystemAddress"] = x.system_address;
        j["Taxi"] = x.taxi;
        j["timestamp"] = x.timestamp;
    }
}


