//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     cancelled_squadron_application data = nlohmann::json::parse(jsonString);

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

    struct cancelled_squadron_application {
        std::string event;
        int64_t squadron_id;
        std::string squadron_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, cancelled_squadron_application & x);
    void to_json(json & j, const cancelled_squadron_application & x);

    inline void from_json(const json & j, cancelled_squadron_application& x) {
        x.event = j.at("event").get<std::string>();
        x.squadron_id = j.at("SquadronID").get<int64_t>();
        x.squadron_name = j.at("SquadronName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const cancelled_squadron_application & x) {
        j = json::object();
        j["event"] = x.event;
        j["SquadronID"] = x.squadron_id;
        j["SquadronName"] = x.squadron_name;
        j["timestamp"] = x.timestamp;
    }
}


