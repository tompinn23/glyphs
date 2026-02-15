//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     faction_kill_bond data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: Player rewarded for taking part in a combat zone
     */
    struct faction_kill_bond {
        std::string awarding_faction;
        std::optional<std::string> awarding_faction_localised;
        std::string event;
        int64_t reward;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string victim_faction;
        std::optional<std::string> victim_faction_localised;
    };
}

namespace hue {
    void from_json(const json & j, faction_kill_bond & x);
    void to_json(json & j, const faction_kill_bond & x);

    inline void from_json(const json & j, faction_kill_bond& x) {
        x.awarding_faction = j.at("AwardingFaction").get<std::string>();
        x.awarding_faction_localised = get_stack_optional<std::string>(j, "AwardingFaction_Localised");
        x.event = j.at("event").get<std::string>();
        x.reward = j.at("Reward").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.victim_faction = j.at("VictimFaction").get<std::string>();
        x.victim_faction_localised = get_stack_optional<std::string>(j, "VictimFaction_Localised");
    }

    inline void to_json(json & j, const faction_kill_bond & x) {
        j = json::object();
        j["AwardingFaction"] = x.awarding_faction;
        j["AwardingFaction_Localised"] = x.awarding_faction_localised;
        j["event"] = x.event;
        j["Reward"] = x.reward;
        j["timestamp"] = x.timestamp;
        j["VictimFaction"] = x.victim_faction;
        j["VictimFaction_Localised"] = x.victim_faction_localised;
    }
}


