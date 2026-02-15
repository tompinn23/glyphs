//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     trade_micro_resources data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct offer {
        std::string category;
        int64_t count;
        std::string name;
        std::optional<std::string> name_localised;
    };

    /**
     * This event is logged when the player exchanges owned microresources to receive some other
     * type of microresource
     */
    struct trade_micro_resources {
        std::string category;
        int64_t count;
        std::string event;
        int64_t market_id;
        std::vector<offer> offered;
        std::string received;
        std::optional<std::string> received_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t total_count;
    };
}

namespace hue {
    void from_json(const json & j, offer & x);
    void to_json(json & j, const offer & x);

    void from_json(const json & j, trade_micro_resources & x);
    void to_json(json & j, const trade_micro_resources & x);

    inline void from_json(const json & j, offer& x) {
        x.category = j.at("Category").get<std::string>();
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const offer & x) {
        j = json::object();
        j["Category"] = x.category;
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, trade_micro_resources& x) {
        x.category = j.at("Category").get<std::string>();
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.offered = j.at("Offered").get<std::vector<offer>>();
        x.received = j.at("Received").get<std::string>();
        x.received_localised = get_stack_optional<std::string>(j, "Received_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_count = j.at("TotalCount").get<int64_t>();
    }

    inline void to_json(json & j, const trade_micro_resources & x) {
        j = json::object();
        j["Category"] = x.category;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Offered"] = x.offered;
        j["Received"] = x.received;
        j["Received_Localised"] = x.received_localised;
        j["timestamp"] = x.timestamp;
        j["TotalCount"] = x.total_count;
    }
}


