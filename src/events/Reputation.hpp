//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     reputation data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: at startup (after Rank and Progress). This gives the player's reputation
     * (on a scale of -100..+100) with the superpowers
     */
    struct reputation {
        std::optional<double> alliance;
        std::optional<double> empire;
        std::string event;
        std::optional<double> federation;
        std::optional<double> independent;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, reputation & x);
    void to_json(json & j, const reputation & x);

    inline void from_json(const json & j, reputation& x) {
        x.alliance = get_stack_optional<double>(j, "Alliance");
        x.empire = get_stack_optional<double>(j, "Empire");
        x.event = j.at("event").get<std::string>();
        x.federation = get_stack_optional<double>(j, "Federation");
        x.independent = get_stack_optional<double>(j, "Independent");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const reputation & x) {
        j = json::object();
        j["Alliance"] = x.alliance;
        j["Empire"] = x.empire;
        j["event"] = x.event;
        j["Federation"] = x.federation;
        j["Independent"] = x.independent;
        j["timestamp"] = x.timestamp;
    }
}


