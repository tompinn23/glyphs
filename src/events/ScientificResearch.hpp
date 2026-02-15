//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     scientific_research data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when contributing materials to a research community goal
     */
    struct scientific_research {
        std::string category;
        int64_t count;
        std::string event;
        int64_t market_id;
        std::string name;
        /**
         * The localised value will be omitted if it is exactly the same as Name
         */
        std::optional<std::string> name_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, scientific_research & x);
    void to_json(json & j, const scientific_research & x);

    inline void from_json(const json & j, scientific_research& x) {
        x.category = j.at("Category").get<std::string>();
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const scientific_research & x) {
        j = json::object();
        j["Category"] = x.category;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["timestamp"] = x.timestamp;
    }
}


