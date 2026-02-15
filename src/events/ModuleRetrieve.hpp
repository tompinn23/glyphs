//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     module_retrieve data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when fetching a previously stored module
     */
    struct module_retrieve {
        std::optional<std::string> engineer_modifications;
        std::string event;
        bool hot;
        std::optional<int64_t> level;
        int64_t market_id;
        std::optional<double> quality;
        std::string retrieved_item;
        std::optional<std::string> retrieved_item_localised;
        std::string ship;
        int64_t ship_id;
        std::string slot;
        /**
         * If slot was not empty
         */
        std::optional<std::string> swap_out_item;
        /**
         * If slot was not empty
         */
        std::optional<std::string> swap_out_item_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, module_retrieve & x);
    void to_json(json & j, const module_retrieve & x);

    inline void from_json(const json & j, module_retrieve& x) {
        x.engineer_modifications = get_stack_optional<std::string>(j, "EngineerModifications");
        x.event = j.at("event").get<std::string>();
        x.hot = j.at("Hot").get<bool>();
        x.level = get_stack_optional<int64_t>(j, "Level");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.quality = get_stack_optional<double>(j, "Quality");
        x.retrieved_item = j.at("RetrievedItem").get<std::string>();
        x.retrieved_item_localised = get_stack_optional<std::string>(j, "RetrievedItem_Localised");
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.slot = j.at("Slot").get<std::string>();
        x.swap_out_item = get_stack_optional<std::string>(j, "SwapOutItem");
        x.swap_out_item_localised = get_stack_optional<std::string>(j, "SwapOutItem_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const module_retrieve & x) {
        j = json::object();
        j["EngineerModifications"] = x.engineer_modifications;
        j["event"] = x.event;
        j["Hot"] = x.hot;
        j["Level"] = x.level;
        j["MarketID"] = x.market_id;
        j["Quality"] = x.quality;
        j["RetrievedItem"] = x.retrieved_item;
        j["RetrievedItem_Localised"] = x.retrieved_item_localised;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["Slot"] = x.slot;
        j["SwapOutItem"] = x.swap_out_item;
        j["SwapOutItem_Localised"] = x.swap_out_item_localised;
        j["timestamp"] = x.timestamp;
    }
}


