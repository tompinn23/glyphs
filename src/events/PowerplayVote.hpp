//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay_vote data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when voting for a system expansion
     */
    struct powerplay_vote {
        std::string event;
        std::string power;
        /**
         * Documented, but appears to be unused.
         */
        std::optional<std::string> system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t votes;
        int64_t vote_to_consolidate;
    };
}

namespace hue {
    void from_json(const json & j, powerplay_vote & x);
    void to_json(json & j, const powerplay_vote & x);

    inline void from_json(const json & j, powerplay_vote& x) {
        x.event = j.at("event").get<std::string>();
        x.power = j.at("Power").get<std::string>();
        x.system = get_stack_optional<std::string>(j, "System");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.votes = j.at("Votes").get<int64_t>();
        x.vote_to_consolidate = j.at("VoteToConsolidate").get<int64_t>();
    }

    inline void to_json(json & j, const powerplay_vote & x) {
        j = json::object();
        j["event"] = x.event;
        j["Power"] = x.power;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
        j["Votes"] = x.votes;
        j["VoteToConsolidate"] = x.vote_to_consolidate;
    }
}


