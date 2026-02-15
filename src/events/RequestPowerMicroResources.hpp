//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     request_power_micro_resources data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    /**
     * When Written: when requesting power micro-resources.
     */
    struct request_power_micro_resources {
        std::string event;
        /**
         * The ID of the market where the request took place.
         */
        int64_t market_id;
        /**
         * Details of the micro-resources requested.
         */
        std::vector<common::micro_resource> micro_resources;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * The total number of micro-resources requested.
         */
        int64_t total_count;
    };
}

namespace hue {

    void from_json(const json & j, request_power_micro_resources & x);
    void to_json(json & j, const request_power_micro_resources & x);



    inline void from_json(const json & j, request_power_micro_resources& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.micro_resources = j.at("MicroResources").get<std::vector<common::micro_resource>>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_count = j.at("TotalCount").get<int64_t>();
    }

    inline void to_json(json & j, const request_power_micro_resources & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["MicroResources"] = x.micro_resources;
        j["timestamp"] = x.timestamp;
        j["TotalCount"] = x.total_count;
    }
}


