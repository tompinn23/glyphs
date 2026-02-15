//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_store data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when storing a module in Outfitting
     */
    struct module_store {
        std::optional<int64_t> cost;
        std::optional<std::string> engineer_modifications;
        std::string event;
        std::optional<bool> hot;
        std::optional<int64_t> level;
        int64_t market_id;
        std::optional<double> quality;
        /**
         * If a core module is stored. Documented, but appears to be unused.
         */
        std::optional<std::string> replacement_item;
        std::string ship;
        int64_t ship_id;
        std::string slot;
        std::string stored_item;
        /**
         * If a core module is stored. Documented, but appears to be unused.
         */
        std::optional<std::string> stored_item_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, module_store & x);
    void to_json(json & j, const module_store & x);

    inline void from_json(const json & j, module_store& x) {
        x.cost = get_stack_optional<int64_t>(j, "Cost");
        x.engineer_modifications = get_stack_optional<std::string>(j, "EngineerModifications");
        x.event = j.at("event").get<std::string>();
        x.hot = get_stack_optional<bool>(j, "Hot");
        x.level = get_stack_optional<int64_t>(j, "Level");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.quality = get_stack_optional<double>(j, "Quality");
        x.replacement_item = get_stack_optional<std::string>(j, "ReplacementItem");
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.slot = j.at("Slot").get<std::string>();
        x.stored_item = j.at("StoredItem").get<std::string>();
        x.stored_item_localised = get_stack_optional<std::string>(j, "StoredItem_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const module_store & x) {
        j = json::object();
        j["Cost"] = x.cost;
        j["EngineerModifications"] = x.engineer_modifications;
        j["event"] = x.event;
        j["Hot"] = x.hot;
        j["Level"] = x.level;
        j["MarketID"] = x.market_id;
        j["Quality"] = x.quality;
        j["ReplacementItem"] = x.replacement_item;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["Slot"] = x.slot;
        j["StoredItem"] = x.stored_item;
        j["StoredItem_Localised"] = x.stored_item_localised;
        j["timestamp"] = x.timestamp;
    }
}


