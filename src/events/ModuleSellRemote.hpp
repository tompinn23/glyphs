//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_sell_remote data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when selling a module in storage at another station
     */
    struct module_sell_remote {
        std::string event;
        std::string sell_item;
        std::optional<std::string> sell_item_localised;
        int64_t sell_price;
        int64_t server_id;
        std::string ship;
        int64_t ship_id;
        int64_t storage_slot;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, module_sell_remote & x);
    void to_json(json & j, const module_sell_remote & x);

    inline void from_json(const json & j, module_sell_remote& x) {
        x.event = j.at("event").get<std::string>();
        x.sell_item = j.at("SellItem").get<std::string>();
        x.sell_item_localised = get_stack_optional<std::string>(j, "SellItem_Localised");
        x.sell_price = j.at("SellPrice").get<int64_t>();
        x.server_id = j.at("ServerId").get<int64_t>();
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.storage_slot = j.at("StorageSlot").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const module_sell_remote & x) {
        j = json::object();
        j["event"] = x.event;
        j["SellItem"] = x.sell_item;
        j["SellItem_Localised"] = x.sell_item_localised;
        j["SellPrice"] = x.sell_price;
        j["ServerId"] = x.server_id;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["StorageSlot"] = x.storage_slot;
        j["timestamp"] = x.timestamp;
    }
}


