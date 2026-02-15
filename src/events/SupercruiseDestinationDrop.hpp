//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     supercruise_destination_drop data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When dropping out of supercruise at a targeted destination
     */
    struct supercruise_destination_drop {
        std::string event;
        std::optional<int64_t> market_id;
        int64_t threat;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
        std::optional<std::string> type_localised;
    };
}

namespace hue {
    void from_json(const json & j, supercruise_destination_drop & x);
    void to_json(json & j, const supercruise_destination_drop & x);

    inline void from_json(const json & j, supercruise_destination_drop& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = get_stack_optional<int64_t>(j, "MarketID");
        x.threat = j.at("Threat").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const supercruise_destination_drop & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Threat"] = x.threat;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


