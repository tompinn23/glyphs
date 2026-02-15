//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     promotion data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when the playerΓÇÖs rank increases. Only the relevant ranks are included.
     */
    struct promotion {
        std::optional<int64_t> combat;
        std::optional<int64_t> empire;
        std::string event;
        std::optional<int64_t> exobiologist;
        std::optional<int64_t> explore;
        std::optional<int64_t> federation;
        std::optional<int64_t> soldier;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<int64_t> trade;
    };
}

namespace hue {
    void from_json(const json & j, promotion & x);
    void to_json(json & j, const promotion & x);

    inline void from_json(const json & j, promotion& x) {
        x.combat = get_stack_optional<int64_t>(j, "Combat");
        x.empire = get_stack_optional<int64_t>(j, "Empire");
        x.event = j.at("event").get<std::string>();
        x.exobiologist = get_stack_optional<int64_t>(j, "Exobiologist");
        x.explore = get_stack_optional<int64_t>(j, "Explore");
        x.federation = get_stack_optional<int64_t>(j, "Federation");
        x.soldier = get_stack_optional<int64_t>(j, "Soldier");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.trade = get_stack_optional<int64_t>(j, "Trade");
    }

    inline void to_json(json & j, const promotion & x) {
        j = json::object();
        j["Combat"] = x.combat;
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


