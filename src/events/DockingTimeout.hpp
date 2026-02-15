//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     docking_timeout data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when a docking request has timed out
     */
    struct docking_timeout {
        std::string event;
        std::optional<int64_t> market_id;
        std::optional<std::string> station_name;
        std::optional<std::string> station_name_localised;
        std::optional<std::string> station_type;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, docking_timeout & x);
    void to_json(json & j, const docking_timeout & x);

    inline void from_json(const json & j, docking_timeout& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = get_stack_optional<int64_t>(j, "MarketID");
        x.station_name = get_stack_optional<std::string>(j, "StationName");
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_type = get_stack_optional<std::string>(j, "StationType");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const docking_timeout & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["StationName"] = x.station_name;
        j["StationName_Localised"] = x.station_name_localised;
        j["StationType"] = x.station_type;
        j["timestamp"] = x.timestamp;
    }
}


