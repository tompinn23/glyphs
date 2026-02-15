//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     escape_interdiction data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: Player has escaped interdiction
     */
    struct escape_interdiction {
        std::string event;
        std::string interdictor;
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
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, escape_interdiction & x);
    void to_json(json & j, const escape_interdiction & x);

    inline void from_json(const json & j, escape_interdiction& x) {
        x.event = j.at("event").get<std::string>();
        x.interdictor = j.at("Interdictor").get<std::string>();
        x.interdictor_localised = get_stack_optional<std::string>(j, "Interdictor_Localised");
        x.is_player = j.at("IsPlayer").get<bool>();
        x.is_thargoid = get_stack_optional<bool>(j, "IsThargoid");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const escape_interdiction & x) {
        j = json::object();
        j["event"] = x.event;
        j["Interdictor"] = x.interdictor;
        j["Interdictor_Localised"] = x.interdictor_localised;
        j["IsPlayer"] = x.is_player;
        j["IsThargoid"] = x.is_thargoid;
        j["timestamp"] = x.timestamp;
    }
}


