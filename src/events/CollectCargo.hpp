//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     collect_cargo data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when scooping cargo from space or planet surface
     */
    struct collect_cargo {
        std::string event;
        std::optional<int64_t> mission_id;
        bool stolen;
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
    void from_json(const json & j, collect_cargo & x);
    void to_json(json & j, const collect_cargo & x);

    inline void from_json(const json & j, collect_cargo& x) {
        x.event = j.at("event").get<std::string>();
        x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
        x.stolen = j.at("Stolen").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const collect_cargo & x) {
        j = json::object();
        j["event"] = x.event;
        j["MissionID"] = x.mission_id;
        j["Stolen"] = x.stolen;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


