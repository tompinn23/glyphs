//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     heat_damage data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when taking damage due to overheating
     */
    struct heat_damage {
        std::string event;
        std::optional<int64_t> id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, heat_damage & x);
    void to_json(json & j, const heat_damage & x);

    inline void from_json(const json & j, heat_damage& x) {
        x.event = j.at("event").get<std::string>();
        x.id = get_stack_optional<int64_t>(j, "ID");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const heat_damage & x) {
        j = json::object();
        j["event"] = x.event;
        j["ID"] = x.id;
        j["timestamp"] = x.timestamp;
    }
}


