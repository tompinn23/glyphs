//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     collect_items data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When picking up items from the ground
     */
    struct collect_items {
        int64_t count;
        std::string event;
        std::string name;
        /**
         * The localised value will be omitted if it is exactly the same as Name
         */
        std::optional<std::string> name_localised;
        int64_t owner_id;
        bool stolen;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
    };
}

namespace hue {
    void from_json(const json & j, collect_items & x);
    void to_json(json & j, const collect_items & x);

    inline void from_json(const json & j, collect_items& x) {
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.owner_id = j.at("OwnerID").get<int64_t>();
        x.stolen = j.at("Stolen").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
    }

    inline void to_json(json & j, const collect_items & x) {
        j = json::object();
        j["Count"] = x.count;
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["OwnerID"] = x.owner_id;
        j["Stolen"] = x.stolen;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
    }
}


