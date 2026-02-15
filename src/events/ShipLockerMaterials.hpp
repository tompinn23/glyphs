//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ship_locker_materials data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct datum {
        int64_t count;
        std::optional<int64_t> mission_id;
        std::string name;
        std::optional<std::string> name_localised;
        int64_t owner_id;
    };
    /**
     * Same as ShipLocker, but discontinued.
     */
    struct ship_locker_materials {
        std::vector<common::component> components;
        std::vector<common::consumable> consumables;
        std::vector<datum> data;
        std::string event;
        std::vector<common::backpack_item> items;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {

    void from_json(const json & j, datum & x);
    void to_json(json & j, const datum & x);

    void from_json(const json & j, ship_locker_materials & x);
    void to_json(json & j, const ship_locker_materials & x);

    inline void from_json(const json & j, datum& x) {
        x.count = j.at("Count").get<int64_t>();
        x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.owner_id = j.at("OwnerID").get<int64_t>();
    }

    inline void to_json(json & j, const datum & x) {
        j = json::object();
        j["Count"] = x.count;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["OwnerID"] = x.owner_id;
    }

    inline void from_json(const json & j, ship_locker_materials& x) {
        x.components = j.at("Components").get<std::vector<common::component>>();
        x.consumables = j.at("Consumables").get<std::vector<common::consumable>>();
        x.data = j.at("Data").get<std::vector<datum>>();
        x.event = j.at("event").get<std::string>();
        x.items = j.at("Items").get<std::vector<common::backpack_item>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const ship_locker_materials & x) {
        j = json::object();
        j["Components"] = x.components;
        j["Consumables"] = x.consumables;
        j["Data"] = x.data;
        j["event"] = x.event;
        j["Items"] = x.items;
        j["timestamp"] = x.timestamp;
    }
}


