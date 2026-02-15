//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     backpack data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"

namespace hue {
    using nlohmann::json;



    /**
     * Lists the contents of the backpack, in a separate backpack.json file
     */
    struct backpack {
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


    void from_json(const json & j, backpack & x);
    void to_json(json & j, const backpack & x);



    inline void from_json(const json & j, backpack& x) {
        x.components = get_stack_optional<std::vector<common::component>>(j, "Components");
        x.consumables = get_stack_optional<std::vector<common::consumable>>(j, "Consumables");
        x.data = get_stack_optional<std::vector<common::data>>(j, "Data");
        x.event = j.at("event").get<std::string>();
        x.items = get_stack_optional<std::vector<common::backpack_item>>(j, "Items");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const backpack & x) {
        j = json::object();
        j["Components"] = x.components;
        j["Consumables"] = x.consumables;
        j["Data"] = x.data;
        j["event"] = x.event;
        j["Items"] = x.items;
        j["timestamp"] = x.timestamp;
    }
}


