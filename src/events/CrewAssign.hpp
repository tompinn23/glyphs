//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     crew_assign data = nlohmann::json::parse(jsonString);

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
     * When written: when changing the task assignment of a member of crew
     */
    struct crew_assign {
        int64_t crew_id;
        std::string event;
        std::string name;
        std::string role;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, crew_assign & x);
    void to_json(json & j, const crew_assign & x);

    inline void from_json(const json & j, crew_assign& x) {
        x.crew_id = j.at("CrewID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.role = j.at("Role").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const crew_assign & x) {
        j = json::object();
        j["CrewID"] = x.crew_id;
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Role"] = x.role;
        j["timestamp"] = x.timestamp;
    }
}


