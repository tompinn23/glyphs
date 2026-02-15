//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     progress data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: at startup
     */
    struct progress {
        /**
         * Percentage progress to next rank
         */
        int64_t combat;
        /**
         * Percentage progress to next rank
         */
        int64_t cqc;
        /**
         * Percentage progress to next rank
         */
        int64_t empire;
        std::string event;
        /**
         * Percentage progress to next rank
         */
        std::optional<int64_t> exobiologist;
        /**
         * Percentage progress to next rank
         */
        int64_t explore;
        /**
         * Percentage progress to next rank
         */
        int64_t federation;
        /**
         * Percentage progress to next rank
         */
        std::optional<int64_t> soldier;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Percentage progress to next rank
         */
        int64_t trade;
    };
}

namespace hue {
    void from_json(const json & j, progress & x);
    void to_json(json & j, const progress & x);

    inline void from_json(const json & j, progress& x) {
        x.combat = j.at("Combat").get<int64_t>();
        x.cqc = j.at("CQC").get<int64_t>();
        x.empire = j.at("Empire").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.exobiologist = get_stack_optional<int64_t>(j, "Exobiologist");
        x.explore = j.at("Explore").get<int64_t>();
        x.federation = j.at("Federation").get<int64_t>();
        x.soldier = get_stack_optional<int64_t>(j, "Soldier");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.trade = j.at("Trade").get<int64_t>();
    }

    inline void to_json(json & j, const progress & x) {
        j = json::object();
        j["Combat"] = x.combat;
        j["CQC"] = x.cqc;
        j["Empire"] = x.empire;
        j["event"] = x.event;
        j["Exobiologist"] = x.exobiologist;
        j["Explore"] = x.explore;
        j["Federation"] = x.federation;
        j["Soldier"] = x.soldier;
        j["timestamp"] = x.timestamp;
        j["Trade"] = x.trade;
    }
}


