//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     buy_micro_resources data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    /**
     * This event is logged when buying microresources
     */
    struct buy_micro_resources {
        std::optional<std::string> category;
        /**
         * Old format (used for example at supplies vendor)
         */
        std::optional<int64_t> count;
        std::string event;
        int64_t market_id;
        /**
         * New format (eg at Fleet Carrier bartender)
         */
        std::optional<std::vector<common::micro_resource>> micro_resources;
        /**
         * Old format (used for example at supplies vendor)
         */
        std::optional<std::string> name;
        /**
         * Old format (used for example at supplies vendor)
         */
        std::optional<std::string> name_localised;
        int64_t price;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * New format (eg at Fleet Carrier bartender)
         */
        std::optional<int64_t> total_count;
    };
}

namespace hue {
    void from_json(const json & j, buy_micro_resources & x);
    void to_json(json & j, const buy_micro_resources & x);


    inline void from_json(const json & j, buy_micro_resources& x) {
        x.category = get_stack_optional<std::string>(j, "Category");
        x.count = get_stack_optional<int64_t>(j, "Count");
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.micro_resources = get_stack_optional<std::vector<common::micro_resource>>(j, "MicroResources");
        x.name = get_stack_optional<std::string>(j, "Name");
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.price = j.at("Price").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_count = get_stack_optional<int64_t>(j, "TotalCount");
    }

    inline void to_json(json & j, const buy_micro_resources & x) {
        j = json::object();
        j["Category"] = x.category;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["MicroResources"] = x.micro_resources;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Price"] = x.price;
        j["timestamp"] = x.timestamp;
        j["TotalCount"] = x.total_count;
    }
}


