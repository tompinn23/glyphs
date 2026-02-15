//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     community_goal_join data = nlohmann::json::parse(jsonString);

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
     * When Written: when signing up to a community goal
     */
    struct community_goal_join {
        int64_t cgid;
        std::string event;
        std::string name;
        std::string system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, community_goal_join & x);
    void to_json(json & j, const community_goal_join & x);

    inline void from_json(const json & j, community_goal_join& x) {
        x.cgid = j.at("CGID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.system = j.at("System").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const community_goal_join & x) {
        j = json::object();
        j["CGID"] = x.cgid;
        j["event"] = x.event;
        j["Name"] = x.name;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
    }
}


