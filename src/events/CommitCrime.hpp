//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     commit_crime data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when a crime is recorded against the player
     */
    struct commit_crime {
        std::optional<int64_t> bounty;
        std::string crime_type;
        std::string event;
        std::string faction;
        std::optional<int64_t> fine;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<std::string> victim;
        std::optional<std::string> victim_localised;
    };
}

namespace hue {
    void from_json(const json & j, commit_crime & x);
    void to_json(json & j, const commit_crime & x);

    inline void from_json(const json & j, commit_crime& x) {
        x.bounty = get_stack_optional<int64_t>(j, "Bounty");
        x.crime_type = j.at("CrimeType").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.faction = j.at("Faction").get<std::string>();
        x.fine = get_stack_optional<int64_t>(j, "Fine");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.victim = get_stack_optional<std::string>(j, "Victim");
        x.victim_localised = get_stack_optional<std::string>(j, "Victim_Localised");
    }

    inline void to_json(json & j, const commit_crime & x) {
        j = json::object();
        j["Bounty"] = x.bounty;
        j["CrimeType"] = x.crime_type;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["Fine"] = x.fine;
        j["timestamp"] = x.timestamp;
        j["Victim"] = x.victim;
        j["Victim_Localised"] = x.victim_localised;
    }
}


