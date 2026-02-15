//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     upgrade_suit data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct resource {
        int64_t count;
        std::string name;
        std::optional<std::string> name_localised;
    };

    /**
     * This event is logged when the player upgrades their flight suit
     */
    struct upgrade_suit {
        int64_t upgrade_suit_class;
        int64_t cost;
        std::string event;
        std::string name;
        std::optional<std::string> name_localised;
        std::optional<std::vector<resource>> resources;
        int64_t suit_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, resource & x);
    void to_json(json & j, const resource & x);

    void from_json(const json & j, upgrade_suit & x);
    void to_json(json & j, const upgrade_suit & x);

    inline void from_json(const json & j, resource& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const resource & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, upgrade_suit& x) {
        x.upgrade_suit_class = j.at("Class").get<int64_t>();
        x.cost = j.at("Cost").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.resources = get_stack_optional<std::vector<resource>>(j, "Resources");
        x.suit_id = j.at("SuitID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const upgrade_suit & x) {
        j = json::object();
        j["Class"] = x.upgrade_suit_class;
        j["Cost"] = x.cost;
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Resources"] = x.resources;
        j["SuitID"] = x.suit_id;
        j["timestamp"] = x.timestamp;
    }
}


