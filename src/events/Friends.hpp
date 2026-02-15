//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     friends data = nlohmann::json::parse(jsonString);

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
     * When written: when receiving information about a change in a friend's status. Also
     * written at startup for friends who are already online.
     */
    struct friends {
        std::string event;
        /**
         * the friend's commander name
         */
        std::string name;
        /**
         * One of the following: Requested, Declined, Added, Lost, Offline, Online
         */
        std::string status;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, friends & x);
    void to_json(json & j, const friends & x);

    inline void from_json(const json & j, friends& x) {
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.status = j.at("Status").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const friends & x) {
        j = json::object();
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Status"] = x.status;
        j["timestamp"] = x.timestamp;
    }
}


