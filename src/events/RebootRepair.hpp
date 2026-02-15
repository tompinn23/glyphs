//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     reboot_repair data = nlohmann::json::parse(jsonString);

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
     * When written: when the reboot repair function is used
     */
    struct reboot_repair {
        std::string event;
        /**
         * Array of names of modules repaired
         */
        std::vector<std::string> modules;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, reboot_repair & x);
    void to_json(json & j, const reboot_repair & x);

    inline void from_json(const json & j, reboot_repair& x) {
        x.event = j.at("event").get<std::string>();
        x.modules = j.at("Modules").get<std::vector<std::string>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const reboot_repair & x) {
        j = json::object();
        j["event"] = x.event;
        j["Modules"] = x.modules;
        j["timestamp"] = x.timestamp;
    }
}


