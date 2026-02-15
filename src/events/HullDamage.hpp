//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     hull_damage data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when hull health drops below a threshold (20% steps)
     */
    struct hull_damage {
        std::string event;
        /**
         * True for ship-launched fighter
         */
        std::optional<bool> fighter;
        double health;
        /**
         * True if player is piloting the ship/fighter taking damage
         */
        bool player_pilot;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, hull_damage & x);
    void to_json(json & j, const hull_damage & x);

    inline void from_json(const json & j, hull_damage& x) {
        x.event = j.at("event").get<std::string>();
        x.fighter = get_stack_optional<bool>(j, "Fighter");
        x.health = j.at("Health").get<double>();
        x.player_pilot = j.at("PlayerPilot").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const hull_damage & x) {
        j = json::object();
        j["event"] = x.event;
        j["Fighter"] = x.fighter;
        j["Health"] = x.health;
        j["PlayerPilot"] = x.player_pilot;
        j["timestamp"] = x.timestamp;
    }
}


