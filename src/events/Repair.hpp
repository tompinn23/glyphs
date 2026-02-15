//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     repair data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when repairing the ship. When repairing on a FleetCarrier, you can get a
     * list of the modules repaired
     */
    struct repair {
        int64_t cost;
        std::string event;
        /**
         * all, wear, hull, paint, or name of module
         */
        std::optional<std::string> item;
        /**
         * when repairing on a FleetCarrier
         */
        std::optional<std::vector<std::string>> items;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, repair & x);
    void to_json(json & j, const repair & x);

    inline void from_json(const json & j, repair& x) {
        x.cost = j.at("Cost").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.item = get_stack_optional<std::string>(j, "Item");
        x.items = get_stack_optional<std::vector<std::string>>(j, "Items");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const repair & x) {
        j = json::object();
        j["Cost"] = x.cost;
        j["event"] = x.event;
        j["Item"] = x.item;
        j["Items"] = x.items;
        j["timestamp"] = x.timestamp;
    }
}


