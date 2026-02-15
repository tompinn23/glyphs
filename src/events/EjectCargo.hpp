//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     eject_cargo data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When cargo is ejected
     */
    struct eject_cargo {
        bool abandoned;
        int64_t count;
        std::string event;
        std::optional<int64_t> mission_id;
        /**
         * If the cargo is related to powerplay delivery from outlying systems back to the centre.
         * Starsystem name.
         */
        std::optional<std::string> powerplay_origin;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
        /**
         * The localised value will be omitted if it is exactly the same as Type
         */
        std::optional<std::string> type_localised;
    };
}

namespace hue {
    void from_json(const json & j, eject_cargo & x);
    void to_json(json & j, const eject_cargo & x);

    inline void from_json(const json & j, eject_cargo& x) {
        x.abandoned = j.at("Abandoned").get<bool>();
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
        x.powerplay_origin = get_stack_optional<std::string>(j, "PowerplayOrigin");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const eject_cargo & x) {
        j = json::object();
        j["Abandoned"] = x.abandoned;
        j["Count"] = x.count;
        j["event"] = x.event;
        j["MissionID"] = x.mission_id;
        j["PowerplayOrigin"] = x.powerplay_origin;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


