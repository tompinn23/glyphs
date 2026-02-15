//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     squadron_created data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct squadron_created {
        std::string event;
        std::optional<int64_t> squadron_id;
        std::string squadron_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, squadron_created & x);
    void to_json(json & j, const squadron_created & x);

    inline void from_json(const json & j, squadron_created& x) {
        x.event = j.at("event").get<std::string>();
        x.squadron_id = get_stack_optional<int64_t>(j, "SquadronID");
        x.squadron_name = j.at("SquadronName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const squadron_created & x) {
        j = json::object();
        j["event"] = x.event;
        j["SquadronID"] = x.squadron_id;
        j["SquadronName"] = x.squadron_name;
        j["timestamp"] = x.timestamp;
    }
}


