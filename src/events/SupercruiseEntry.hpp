//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     supercruise_entry data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: entering supercruise from normal space
     */
    struct supercruise_entry {
        std::string event;
        std::optional<bool> multicrew;
        std::string star_system;
        int64_t system_address;
        std::optional<bool> taxi;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<bool> wanted;
    };
}

namespace hue {
    void from_json(const json & j, supercruise_entry & x);
    void to_json(json & j, const supercruise_entry & x);

    inline void from_json(const json & j, supercruise_entry& x) {
        x.event = j.at("event").get<std::string>();
        x.multicrew = get_stack_optional<bool>(j, "Multicrew");
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.taxi = get_stack_optional<bool>(j, "Taxi");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.wanted = get_stack_optional<bool>(j, "Wanted");
    }

    inline void to_json(json & j, const supercruise_entry & x) {
        j = json::object();
        j["event"] = x.event;
        j["Multicrew"] = x.multicrew;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["Taxi"] = x.taxi;
        j["timestamp"] = x.timestamp;
        j["Wanted"] = x.wanted;
    }
}


