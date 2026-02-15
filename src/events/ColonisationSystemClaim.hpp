//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     colonisation_system_claim data = nlohmann::json::parse(jsonString);

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
     * When Written: When a system is claimed for colonisation by paying for the claim.
     */
    struct colonisation_system_claim {
        std::string event;
        std::string star_system;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, colonisation_system_claim & x);
    void to_json(json & j, const colonisation_system_claim & x);

    inline void from_json(const json & j, colonisation_system_claim& x) {
        x.event = j.at("event").get<std::string>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const colonisation_system_claim & x) {
        j = json::object();
        j["event"] = x.event;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


