//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     resurrect data = nlohmann::json::parse(jsonString);

#pragma once

#include "nlohmann/json.hpp"

namespace hue {
    using nlohmann::json;

    #ifndef NLOHMANN_UNTYPED_hue_HELPER
    #define NLOHMANN_UNTYPED_hue_HELPER
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    #endif

    /**
     * When written: when the player restarts after death
     */
    struct resurrect {
        /**
         * Whether the commander declared bankruptcy
         */
        bool bankrupt;
        /**
         * The price paid
         */
        int64_t cost;
        std::string event;
        /**
         * The option selected on the insurance rebuy screen
         */
        std::string option;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, resurrect & x);
    void to_json(json & j, const resurrect & x);

    inline void from_json(const json & j, resurrect& x) {
        x.bankrupt = j.at("Bankrupt").get<bool>();
        x.cost = j.at("Cost").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.option = j.at("Option").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const resurrect & x) {
        j = json::object();
        j["Bankrupt"] = x.bankrupt;
        j["Cost"] = x.cost;
        j["event"] = x.event;
        j["Option"] = x.option;
        j["timestamp"] = x.timestamp;
    }
}


