//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fss_all_bodies_found data = nlohmann::json::parse(jsonString);

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
     * When written: after having identified all bodies in the system
     */
    struct fss_all_bodies_found {
        int64_t count;
        std::string event;
        int64_t system_address;
        std::string system_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, fss_all_bodies_found & x);
    void to_json(json & j, const fss_all_bodies_found & x);

    inline void from_json(const json & j, fss_all_bodies_found& x) {
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.system_name = j.at("SystemName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const fss_all_bodies_found & x) {
        j = json::object();
        j["Count"] = x.count;
        j["event"] = x.event;
        j["SystemAddress"] = x.system_address;
        j["SystemName"] = x.system_name;
        j["timestamp"] = x.timestamp;
    }
}


