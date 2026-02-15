//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ship_locker data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    /**
     * Lists the contents of the ship locker, eg at startup. The full contents are written to a
     * separate file, ShipLocker.json. The full list is also written into the journal at startup
     * (if in a ship) and when boarding a ship. The shiplocker.json file is updated when the
     * locker contents are changed.
     */
    struct ship_locker {
        std::optional<std::vector<common::component>> components;
        std::optional<std::vector<common::consumable>> consumables;
        std::optional<std::vector<common::data>> data;
        std::string event;
        std::optional<std::vector<common::backpack_item>> items;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {

    void from_json(const json & j, ship_locker & x);
    void to_json(json & j, const ship_locker & x);

    inline void from_json(const json & j, ship_locker& x) {
        x.components = get_stack_optional<std::vector<common::component>>(j, "Components");
        x.consumables = get_stack_optional<std::vector<common::consumable>>(j, "Consumables");
        x.data = get_stack_optional<std::vector<common::data>>(j, "Data");
        x.event = j.at("event").get<std::string>();
        x.items = get_stack_optional<std::vector<common::backpack_item>>(j, "Items");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const ship_locker & x) {
        j = json::object();
        j["Components"] = x.components;
        j["Consumables"] = x.consumables;
        j["Data"] = x.data;
        j["event"] = x.event;
        j["Items"] = x.items;
        j["timestamp"] = x.timestamp;
    }
}


