//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     stored_modules data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct stored_module_item {
        int64_t buy_price;
        /**
         * If engineered module
         */
        std::optional<std::string> engineer_modifications;
        bool hot;
        /**
         * If the module is being transferred
         */
        std::optional<bool> in_transit;
        /**
         * If engineered module
         */
        std::optional<int64_t> level;
        std::optional<int64_t> market_id;
        std::string name;
        std::optional<std::string> name_localised;
        /**
         * If engineered module
         */
        std::optional<double> quality;
        std::optional<std::string> star_system;
        int64_t storage_slot;
        std::optional<int64_t> transfer_cost;
        std::optional<int64_t> transfer_time;
    };

    /**
     * When written: when first visiting Outfitting, and when the set of stored modules has
     * changed
     */
    struct stored_modules {
        std::string event;
        std::vector<stored_module_item> items;
        int64_t market_id;
        std::string star_system;
        std::string station_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, stored_module_item & x);
    void to_json(json & j, const stored_module_item & x);

    void from_json(const json & j, stored_modules & x);
    void to_json(json & j, const stored_modules & x);

    inline void from_json(const json & j, stored_module_item& x) {
        x.buy_price = j.at("BuyPrice").get<int64_t>();
        x.engineer_modifications = get_stack_optional<std::string>(j, "EngineerModifications");
        x.hot = j.at("Hot").get<bool>();
        x.in_transit = get_stack_optional<bool>(j, "InTransit");
        x.level = get_stack_optional<int64_t>(j, "Level");
        x.market_id = get_stack_optional<int64_t>(j, "MarketID");
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.quality = get_stack_optional<double>(j, "Quality");
        x.star_system = get_stack_optional<std::string>(j, "StarSystem");
        x.storage_slot = j.at("StorageSlot").get<int64_t>();
        x.transfer_cost = get_stack_optional<int64_t>(j, "TransferCost");
        x.transfer_time = get_stack_optional<int64_t>(j, "TransferTime");
    }

    inline void to_json(json & j, const stored_module_item & x) {
        j = json::object();
        j["BuyPrice"] = x.buy_price;
        j["EngineerModifications"] = x.engineer_modifications;
        j["Hot"] = x.hot;
        j["InTransit"] = x.in_transit;
        j["Level"] = x.level;
        j["MarketID"] = x.market_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Quality"] = x.quality;
        j["StarSystem"] = x.star_system;
        j["StorageSlot"] = x.storage_slot;
        j["TransferCost"] = x.transfer_cost;
        j["TransferTime"] = x.transfer_time;
    }

    inline void from_json(const json & j, stored_modules& x) {
        x.event = j.at("event").get<std::string>();
        x.items = j.at("Items").get<std::vector<stored_module_item>>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_name = j.at("StationName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const stored_modules & x) {
        j = json::object();
        j["event"] = x.event;
        j["Items"] = x.items;
        j["MarketID"] = x.market_id;
        j["StarSystem"] = x.star_system;
        j["StationName"] = x.station_name;
        j["timestamp"] = x.timestamp;
    }
}


