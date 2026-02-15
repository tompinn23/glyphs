//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fss_signal_discovered data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when zooming in on a signal using the FSS scanner
     */
    struct fss_signal_discovered {
        std::string event;
        /**
         * If it is a station
         */
        std::optional<bool> is_station;
        /**
         * the opposing power, if relevant
         */
        std::optional<std::string> opposing_power;
        std::string signal_name;
        std::optional<std::string> signal_name_localised;
        std::optional<std::string> signal_type;
        /**
         * the minor faction, if relevant
         */
        std::optional<std::string> spawning_faction;
        std::optional<std::string> spawning_faction_localised;
        /**
         * the spawning power, if relevant
         */
        std::optional<std::string> spawning_power;
        /**
         * the BGS state that triggered this event, if relevant
         */
        std::optional<std::string> spawning_state;
        std::optional<std::string> spawning_state_localised;
        int64_t system_address;
        /**
         * If a Unidentified Signal Source(USS) Event
         */
        std::optional<int64_t> threat_level;
        /**
         * remaining lifetime in seconds, if relevant
         */
        std::optional<double> time_remaining;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * If a Unidentified Signal Source(USS) Event
         */
        std::optional<std::string> uss_type;
        /**
         * If a Unidentified Signal Source(USS) Event
         */
        std::optional<std::string> uss_type_localised;
    };
}

namespace hue {
    void from_json(const json & j, fss_signal_discovered & x);
    void to_json(json & j, const fss_signal_discovered & x);

    inline void from_json(const json & j, fss_signal_discovered& x) {
        x.event = j.at("event").get<std::string>();
        x.is_station = get_stack_optional<bool>(j, "IsStation");
        x.opposing_power = get_stack_optional<std::string>(j, "OpposingPower");
        x.signal_name = j.at("SignalName").get<std::string>();
        x.signal_name_localised = get_stack_optional<std::string>(j, "SignalName_Localised");
        x.signal_type = get_stack_optional<std::string>(j, "SignalType");
        x.spawning_faction = get_stack_optional<std::string>(j, "SpawningFaction");
        x.spawning_faction_localised = get_stack_optional<std::string>(j, "SpawningFaction_Localised");
        x.spawning_power = get_stack_optional<std::string>(j, "SpawningPower");
        x.spawning_state = get_stack_optional<std::string>(j, "SpawningState");
        x.spawning_state_localised = get_stack_optional<std::string>(j, "SpawningState_Localised");
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.threat_level = get_stack_optional<int64_t>(j, "ThreatLevel");
        x.time_remaining = get_stack_optional<double>(j, "TimeRemaining");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.uss_type = get_stack_optional<std::string>(j, "USSType");
        x.uss_type_localised = get_stack_optional<std::string>(j, "USSType_Localised");
    }

    inline void to_json(json & j, const fss_signal_discovered & x) {
        j = json::object();
        j["event"] = x.event;
        j["IsStation"] = x.is_station;
        j["OpposingPower"] = x.opposing_power;
        j["SignalName"] = x.signal_name;
        j["SignalName_Localised"] = x.signal_name_localised;
        j["SignalType"] = x.signal_type;
        j["SpawningFaction"] = x.spawning_faction;
        j["SpawningFaction_Localised"] = x.spawning_faction_localised;
        j["SpawningPower"] = x.spawning_power;
        j["SpawningState"] = x.spawning_state;
        j["SpawningState_Localised"] = x.spawning_state_localised;
        j["SystemAddress"] = x.system_address;
        j["ThreatLevel"] = x.threat_level;
        j["TimeRemaining"] = x.time_remaining;
        j["timestamp"] = x.timestamp;
        j["USSType"] = x.uss_type;
        j["USSType_Localised"] = x.uss_type_localised;
    }
}


