//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     died data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct killer {
        std::string killer_name;
        std::optional<std::string> killer_name_localised;
        std::string killer_rank;
        std::string killer_ship;
    };

    /**
     * When written: player was killed
     */
    struct died {
        std::string event;
        /**
         * When killed by a single entity
         */
        std::optional<std::string> killer_name;
        /**
         * When killed by a single entity
         */
        std::optional<std::string> killer_name_localised;
        /**
         * When killed by a single entity
         */
        std::optional<std::string> killer_rank;
        /**
         * When killed by a wing
         */
        std::optional<std::vector<killer>> killers;
        /**
         * When killed by a single entity
         */
        std::optional<std::string> killer_ship;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, killer & x);
    void to_json(json & j, const killer & x);

    void from_json(const json & j, died & x);
    void to_json(json & j, const died & x);

    inline void from_json(const json & j, killer& x) {
        x.killer_name = j.at("KillerName").get<std::string>();
        x.killer_name_localised = get_stack_optional<std::string>(j, "KillerName_Localised");
        x.killer_rank = j.at("KillerRank").get<std::string>();
        x.killer_ship = j.at("KillerShip").get<std::string>();
    }

    inline void to_json(json & j, const killer & x) {
        j = json::object();
        j["KillerName"] = x.killer_name;
        j["KillerName_Localised"] = x.killer_name_localised;
        j["KillerRank"] = x.killer_rank;
        j["KillerShip"] = x.killer_ship;
    }

    inline void from_json(const json & j, died& x) {
        x.event = j.at("event").get<std::string>();
        x.killer_name = get_stack_optional<std::string>(j, "KillerName");
        x.killer_name_localised = get_stack_optional<std::string>(j, "KillerName_Localised");
        x.killer_rank = get_stack_optional<std::string>(j, "KillerRank");
        x.killers = get_stack_optional<std::vector<killer>>(j, "Killers");
        x.killer_ship = get_stack_optional<std::string>(j, "KillerShip");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const died & x) {
        j = json::object();
        j["event"] = x.event;
        j["KillerName"] = x.killer_name;
        j["KillerName_Localised"] = x.killer_name_localised;
        j["KillerRank"] = x.killer_rank;
        j["Killers"] = x.killers;
        j["KillerShip"] = x.killer_ship;
        j["timestamp"] = x.timestamp;
    }
}


