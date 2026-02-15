//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     interdiction data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct interdiction {
        /**
         * If a player
         */
        std::optional<int64_t> combat_rank;
        std::string event;
        /**
         * If npc
         */
        std::optional<std::string> faction;
        /**
         * Victim pilot name
         */
        std::string interdicted;
        /**
         * Victim pilot name
         */
        std::optional<std::string> interdicted_localised;
        /**
         * Whether player or npc
         */
        bool is_player;
        /**
         * If npc is working for a power
         */
        std::optional<std::string> power;
        std::optional<bool> submitted;
        bool success;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, interdiction & x);
    void to_json(json & j, const interdiction & x);

    inline void from_json(const json & j, interdiction& x) {
        x.combat_rank = get_stack_optional<int64_t>(j, "CombatRank");
        x.event = j.at("event").get<std::string>();
        x.faction = get_stack_optional<std::string>(j, "Faction");
        x.interdicted = j.at("Interdicted").get<std::string>();
        x.interdicted_localised = get_stack_optional<std::string>(j, "Interdicted_Localised");
        x.is_player = j.at("IsPlayer").get<bool>();
        x.power = get_stack_optional<std::string>(j, "Power");
        x.submitted = get_stack_optional<bool>(j, "Submitted");
        x.success = j.at("Success").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const interdiction & x) {
        j = json::object();
        j["CombatRank"] = x.combat_rank;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["Interdicted"] = x.interdicted;
        j["Interdicted_Localised"] = x.interdicted_localised;
        j["IsPlayer"] = x.is_player;
        j["Power"] = x.power;
        j["Submitted"] = x.submitted;
        j["Success"] = x.success;
        j["timestamp"] = x.timestamp;
    }
}


