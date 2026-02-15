//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     docking_denied data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when the station denies a docking request
     */
    struct docking_denied {
        std::string event;
        int64_t market_id;
        std::string reason;
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
    void from_json(const json & j, docking_denied & x);
    void to_json(json & j, const docking_denied & x);

    inline void from_json(const json & j, docking_denied& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.reason = j.at("Reason").get<std::string>();
        x.station_name = j.at("StationName").get<std::string>();
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_type = j.at("StationType").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const docking_denied & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Reason"] = x.reason;
        j["StationName"] = x.station_name;
        j["StationName_Localised"] = x.station_name_localised;
        j["StationType"] = x.station_type;
        j["timestamp"] = x.timestamp;
    }
}


