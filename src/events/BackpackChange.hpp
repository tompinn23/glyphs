//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     backpack_change data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct change_entry {
        int64_t count;
        std::optional<int64_t> mission_id;
        std::string name;
        std::optional<std::string> name_localised;
        int64_t owner_id;
        std::string type;
    };

    /**
     * This is written when there is any change to the contents of the suit backpack ΓÇô note this
     * can be written at the same time as other events like UseConsumable
     */
    struct backpack_change {
        std::optional<std::vector<change_entry>> added;
        std::string event;
        std::optional<std::vector<change_entry>> removed;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, change_entry & x);
    void to_json(json & j, const change_entry & x);

    void from_json(const json & j, backpack_change & x);
    void to_json(json & j, const backpack_change & x);

    inline void from_json(const json & j, change_entry& x) {
        x.count = j.at("Count").get<int64_t>();
        x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.owner_id = j.at("OwnerID").get<int64_t>();
        x.type = j.at("Type").get<std::string>();
    }

    inline void to_json(json & j, const change_entry & x) {
        j = json::object();
        j["Count"] = x.count;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["OwnerID"] = x.owner_id;
        j["Type"] = x.type;
    }

    inline void from_json(const json & j, backpack_change& x) {
        x.added = get_stack_optional<std::vector<change_entry>>(j, "Added");
        x.event = j.at("event").get<std::string>();
        x.removed = get_stack_optional<std::vector<change_entry>>(j, "Removed");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const backpack_change & x) {
        j = json::object();
        j["Added"] = x.added;
        j["event"] = x.event;
        j["Removed"] = x.removed;
        j["timestamp"] = x.timestamp;
    }
}


