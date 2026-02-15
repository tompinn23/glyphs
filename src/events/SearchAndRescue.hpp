//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     search_and_rescue data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when delivering items to a Search and Rescue contact
     */
    struct search_and_rescue {
        int64_t count;
        std::string event;
        int64_t market_id;
        std::string name;
        std::optional<std::string> name_localised;
        int64_t reward;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, search_and_rescue & x);
    void to_json(json & j, const search_and_rescue & x);

    inline void from_json(const json & j, search_and_rescue& x) {
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.reward = j.at("Reward").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const search_and_rescue & x) {
        j = json::object();
        j["Count"] = x.count;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Reward"] = x.reward;
        j["timestamp"] = x.timestamp;
    }
}


