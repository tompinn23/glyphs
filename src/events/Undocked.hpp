//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     undocked data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: liftoff from a landing pad in a station, outpost or settlement
     */
    struct undocked {
        std::string event;
        int64_t market_id;
        std::optional<bool> multicrew;
        std::string station_name;
        std::optional<std::string> station_name_localised;
        std::string station_type;
        std::optional<bool> taxi;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, undocked & x);
    void to_json(json & j, const undocked & x);

    inline void from_json(const json & j, undocked& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.multicrew = get_stack_optional<bool>(j, "Multicrew");
        x.station_name = j.at("StationName").get<std::string>();
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_type = j.at("StationType").get<std::string>();
        x.taxi = get_stack_optional<bool>(j, "Taxi");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const undocked & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Multicrew"] = x.multicrew;
        j["StationName"] = x.station_name;
        j["StationName_Localised"] = x.station_name_localised;
        j["StationType"] = x.station_type;
        j["Taxi"] = x.taxi;
        j["timestamp"] = x.timestamp;
    }
}


