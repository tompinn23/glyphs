//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_swap data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when moving a module to a different slot on the ship
     */
    struct module_swap {
        std::string event;
        std::string from_item;
        std::optional<std::string> from_item_localised;
        std::string from_slot;
        int64_t market_id;
        std::string ship;
        int64_t ship_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string to_item;
        std::optional<std::string> to_item_localised;
        std::string to_slot;
    };
}

namespace hue {
    void from_json(const json & j, module_swap & x);
    void to_json(json & j, const module_swap & x);

    inline void from_json(const json & j, module_swap& x) {
        x.event = j.at("event").get<std::string>();
        x.from_item = j.at("FromItem").get<std::string>();
        x.from_item_localised = get_stack_optional<std::string>(j, "FromItem_Localised");
        x.from_slot = j.at("FromSlot").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.to_item = j.at("ToItem").get<std::string>();
        x.to_item_localised = get_stack_optional<std::string>(j, "ToItem_Localised");
        x.to_slot = j.at("ToSlot").get<std::string>();
    }

    inline void to_json(json & j, const module_swap & x) {
        j = json::object();
        j["event"] = x.event;
        j["FromItem"] = x.from_item;
        j["FromItem_Localised"] = x.from_item_localised;
        j["FromSlot"] = x.from_slot;
        j["MarketID"] = x.market_id;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["timestamp"] = x.timestamp;
        j["ToItem"] = x.to_item;
        j["ToItem_Localised"] = x.to_item_localised;
        j["ToSlot"] = x.to_slot;
    }
}


