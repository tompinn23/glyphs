//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     dock_fighter data = nlohmann::json::parse(jsonString);

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
     * When written: when docking a fighter back with the mothership
     */
    struct dock_fighter {
        std::string event;
        int64_t id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, dock_fighter & x);
    void to_json(json & j, const dock_fighter & x);

    inline void from_json(const json & j, dock_fighter& x) {
        x.event = j.at("event").get<std::string>();
        x.id = j.at("ID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const dock_fighter & x) {
        j = json::object();
        j["event"] = x.event;
        j["ID"] = x.id;
        j["timestamp"] = x.timestamp;
    }
}


