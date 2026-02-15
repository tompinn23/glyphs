//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     mass_module_store data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct module_item {
        /**
         * Only if modifications are present
         */
        std::optional<std::string> engineer_modifications;
        /**
         * If there is a fine/bounty associated with the module
         */
        bool hot;
        std::optional<int64_t> level;
        std::string name;
        std::optional<std::string> name_localised;
        std::optional<double> quality;
        std::string slot;
    };

    /**
     * When written: when putting multiple modules into storage
     */
    struct mass_module_store {
        std::string event;
        std::vector<module_item> items;
        int64_t market_id;
        std::string ship;
        int64_t ship_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, module_item & x);
    void to_json(json & j, const module_item & x);

    void from_json(const json & j, mass_module_store & x);
    void to_json(json & j, const mass_module_store & x);

    inline void from_json(const json & j, module_item& x) {
        x.engineer_modifications = get_stack_optional<std::string>(j, "EngineerModifications");
        x.hot = j.at("Hot").get<bool>();
        x.level = get_stack_optional<int64_t>(j, "Level");
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.quality = get_stack_optional<double>(j, "Quality");
        x.slot = j.at("Slot").get<std::string>();
    }

    inline void to_json(json & j, const module_item & x) {
        j = json::object();
        j["EngineerModifications"] = x.engineer_modifications;
        j["Hot"] = x.hot;
        j["Level"] = x.level;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Quality"] = x.quality;
        j["Slot"] = x.slot;
    }

    inline void from_json(const json & j, mass_module_store& x) {
        x.event = j.at("event").get<std::string>();
        x.items = j.at("Items").get<std::vector<module_item>>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.ship = j.at("Ship").get<std::string>();
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const mass_module_store & x) {
        j = json::object();
        j["event"] = x.event;
        j["Items"] = x.items;
        j["MarketID"] = x.market_id;
        j["Ship"] = x.ship;
        j["ShipID"] = x.ship_id;
        j["timestamp"] = x.timestamp;
    }
}


