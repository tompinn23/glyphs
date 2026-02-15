//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     docking_cancelled data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when the player cancels a docking request
     */
    struct docking_cancelled {
        std::string event;
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
    void from_json(const json & j, docking_cancelled & x);
    void to_json(json & j, const docking_cancelled & x);

    inline void from_json(const json & j, docking_cancelled& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.station_name = j.at("StationName").get<std::string>();
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_type = j.at("StationType").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const docking_cancelled & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["StationName"] = x.station_name;
        j["StationName_Localised"] = x.station_name_localised;
        j["StationType"] = x.station_type;
        j["timestamp"] = x.timestamp;
    }
}


