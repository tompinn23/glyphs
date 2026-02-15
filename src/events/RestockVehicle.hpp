//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     restock_vehicle data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when purchasing an SRV or Fighter
     */
    struct restock_vehicle {
        int64_t cost;
        /**
         * Number of vehicles purchased
         */
        int64_t count;
        std::string event;
        std::optional<int64_t> id;
        std::string loadout;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
        std::optional<std::string> type_localised;
    };
}

namespace hue {
    void from_json(const json & j, restock_vehicle & x);
    void to_json(json & j, const restock_vehicle & x);

    inline void from_json(const json & j, restock_vehicle& x) {
        x.cost = j.at("Cost").get<int64_t>();
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.id = get_stack_optional<int64_t>(j, "ID");
        x.loadout = j.at("Loadout").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const restock_vehicle & x) {
        j = json::object();
        j["Cost"] = x.cost;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["ID"] = x.id;
        j["Loadout"] = x.loadout;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


