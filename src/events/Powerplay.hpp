//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: at startup, if player has pledged to a power
     */
    struct powerplay {
        std::string event;
        int64_t merits;
        std::string power;
        int64_t rank;
        /**
         * Time pledged in seconds
         */
        int64_t time_pledged;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<int64_t> votes;
    };
}

namespace hue {
    void from_json(const json & j, powerplay & x);
    void to_json(json & j, const powerplay & x);

    inline void from_json(const json & j, powerplay& x) {
        x.event = j.at("event").get<std::string>();
        x.merits = j.at("Merits").get<int64_t>();
        x.power = j.at("Power").get<std::string>();
        x.rank = j.at("Rank").get<int64_t>();
        x.time_pledged = j.at("TimePledged").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.votes = get_stack_optional<int64_t>(j, "Votes");
    }

    inline void to_json(json & j, const powerplay & x) {
        j = json::object();
        j["event"] = x.event;
        j["Merits"] = x.merits;
        j["Power"] = x.power;
        j["Rank"] = x.rank;
        j["TimePledged"] = x.time_pledged;
        j["timestamp"] = x.timestamp;
        j["Votes"] = x.votes;
    }
}


