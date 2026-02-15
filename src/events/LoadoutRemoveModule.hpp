//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     loadout_remove_module data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * This event is logged when a player removes a weapon from a suit loadout
     */
    struct loadout_remove_module {
        int64_t loadout_remove_module_class;
        std::string event;
        int64_t loadout_id;
        std::string loadout_name;
        /**
         * Weapon or other item removed from loadout
         */
        std::string module_name;
        std::optional<std::string> module_name_localised;
        std::string slot_name;
        int64_t suit_id;
        int64_t suit_module_id;
        std::string suit_name;
        std::optional<std::string> suit_name_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::vector<std::string> weapon_mods;
    };
}

namespace hue {
    void from_json(const json & j, loadout_remove_module & x);
    void to_json(json & j, const loadout_remove_module & x);

    inline void from_json(const json & j, loadout_remove_module& x) {
        x.loadout_remove_module_class = j.at("Class").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.loadout_id = j.at("LoadoutID").get<int64_t>();
        x.loadout_name = j.at("LoadoutName").get<std::string>();
        x.module_name = j.at("ModuleName").get<std::string>();
        x.module_name_localised = get_stack_optional<std::string>(j, "ModuleName_Localised");
        x.slot_name = j.at("SlotName").get<std::string>();
        x.suit_id = j.at("SuitID").get<int64_t>();
        x.suit_module_id = j.at("SuitModuleID").get<int64_t>();
        x.suit_name = j.at("SuitName").get<std::string>();
        x.suit_name_localised = get_stack_optional<std::string>(j, "SuitName_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.weapon_mods = j.at("WeaponMods").get<std::vector<std::string>>();
    }

    inline void to_json(json & j, const loadout_remove_module & x) {
        j = json::object();
        j["Class"] = x.loadout_remove_module_class;
        j["event"] = x.event;
        j["LoadoutID"] = x.loadout_id;
        j["LoadoutName"] = x.loadout_name;
        j["ModuleName"] = x.module_name;
        j["ModuleName_Localised"] = x.module_name_localised;
        j["SlotName"] = x.slot_name;
        j["SuitID"] = x.suit_id;
        j["SuitModuleID"] = x.suit_module_id;
        j["SuitName"] = x.suit_name;
        j["SuitName_Localised"] = x.suit_name_localised;
        j["timestamp"] = x.timestamp;
        j["WeaponMods"] = x.weapon_mods;
    }
}


