//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     sell_weapon data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * This event is logged when a player sells a hand weapon
     */
    struct sell_weapon {
        int64_t sell_weapon_class;
        std::string event;
        std::string name;
        std::optional<std::string> name_localised;
        int64_t price;
        int64_t suit_module_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::vector<std::string> weapon_mods;
    };
}

namespace hue {
    void from_json(const json & j, sell_weapon & x);
    void to_json(json & j, const sell_weapon & x);

    inline void from_json(const json & j, sell_weapon& x) {
        x.sell_weapon_class = j.at("Class").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.price = j.at("Price").get<int64_t>();
        x.suit_module_id = j.at("SuitModuleID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.weapon_mods = j.at("WeaponMods").get<std::vector<std::string>>();
    }

    inline void to_json(json & j, const sell_weapon & x) {
        j = json::object();
        j["Class"] = x.sell_weapon_class;
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Price"] = x.price;
        j["SuitModuleID"] = x.suit_module_id;
        j["timestamp"] = x.timestamp;
        j["WeaponMods"] = x.weapon_mods;
    }
}


