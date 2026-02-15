//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fetch_remote_module data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when requesting a module is transferred from storage at another station
     */
    struct fetch_remote_module {
        std::string event;
        int64_t server_id;
        std::string ship;
        int64_t ship_id;
        int64_t storage_slot;
        std::string stored_item;
        std::optional<std::string> stored_item_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t transfer_cost;
        /**
         * In seconds
         */
        int64_t transfer_time;
    };
}

namespace hue {
    void from_json(const json & j, fetch_remote_module & x);
    void to_json(json & j, const fetch_remote_module & x);

    inline void from_json(const json & j, fetch_remote_module& x) {
        x.event = j.at("event").get<std::string>();
        x.server_id = j.at("ServerId").get<int64_t>();
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.storage_slot = j.at("StorageSlot").get<int64_t>();
        x.stored_item = j.at("StoredItem").get<std::string>();
        x.stored_item_localised = get_stack_optional<std::string>(j, "StoredItem_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.transfer_cost = j.at("TransferCost").get<int64_t>();
        x.transfer_time = j.at("TransferTime").get<int64_t>();
    }

    inline void to_json(json & j, const fetch_remote_module & x) {
        j = json::object();
        j["event"] = x.event;
        j["ServerId"] = x.server_id;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["StorageSlot"] = x.storage_slot;
        j["StoredItem"] = x.stored_item;
        j["StoredItem_Localised"] = x.stored_item_localised;
        j["timestamp"] = x.timestamp;
        j["TransferCost"] = x.transfer_cost;
        j["TransferTime"] = x.transfer_time;
    }
}


