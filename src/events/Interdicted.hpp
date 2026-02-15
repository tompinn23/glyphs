//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     interdicted data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: player was interdicted by player or npc
     */
    struct interdicted {
        /**
         * If player
         */
        std::optional<int64_t> combat_rank;
        std::string event;
        /**
         * If npc
         */
        std::optional<std::string> faction;
        std::optional<std::string> interdictor;
        std::optional<std::string> interdictor_localised;
        /**
         * Whether player or npc
         */
        bool is_player;
        /**
         * Whether thargoid
         */
        std::optional<bool> is_thargoid;
        /**
         * If npc is working for a power
         */
        std::optional<std::string> power;
        bool submitted;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, interdicted & x);
    void to_json(json & j, const interdicted & x);

    inline void from_json(const json & j, interdicted& x) {
        x.combat_rank = get_stack_optional<int64_t>(j, "CombatRank");
        x.event = j.at("event").get<std::string>();
        x.faction = get_stack_optional<std::string>(j, "Faction");
        x.interdictor = get_stack_optional<std::string>(j, "Interdictor");
        x.interdictor_localised = get_stack_optional<std::string>(j, "Interdictor_Localised");
        x.is_player = j.at("IsPlayer").get<bool>();
        x.is_thargoid = get_stack_optional<bool>(j, "IsThargoid");
        x.power = get_stack_optional<std::string>(j, "Power");
        x.submitted = j.at("Submitted").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const interdicted & x) {
        j = json::object();
        j["CombatRank"] = x.combat_rank;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["Interdictor"] = x.interdictor;
        j["Interdictor_Localised"] = x.interdictor_localised;
        j["IsPlayer"] = x.is_player;
        j["IsThargoid"] = x.is_thargoid;
        j["Power"] = x.power;
        j["Submitted"] = x.submitted;
        j["timestamp"] = x.timestamp;
    }
}


