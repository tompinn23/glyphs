//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     docking_requested data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    /**
     * When written: when the player requests docking at a station
     */
    struct docking_requested {
        std::string event;
        std::optional<common::landing_pads> landing_pads;
        int64_t market_id;
        std::string station_name;
        std::optional<std::string> station_name_localised;
        std::string station_type;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {

    void from_json(const json & j, docking_requested & x);
    void to_json(json & j, const docking_requested & x);


    inline void from_json(const json & j, docking_requested& x) {
        x.event = j.at("event").get<std::string>();
        x.landing_pads = get_stack_optional<common::landing_pads>(j, "LandingPads");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.station_name = j.at("StationName").get<std::string>();
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_type = j.at("StationType").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const docking_requested & x) {
        j = json::object();
        j["event"] = x.event;
        j["LandingPads"] = x.landing_pads;
        j["MarketID"] = x.market_id;
        j["StationName"] = x.station_name;
        j["StationName_Localised"] = x.station_name_localised;
        j["StationType"] = x.station_type;
        j["timestamp"] = x.timestamp;
    }
}


