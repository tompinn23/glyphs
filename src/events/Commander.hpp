//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     commander data = nlohmann::json::parse(jsonString);

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
     * When written: at the start of the LoadGame process. This is written before the inventory,
     * loadout, etc
     */
    struct commander {
        std::string event;
        std::string fid;
        std::string name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, commander & x);
    void to_json(json & j, const commander & x);

    inline void from_json(const json & j, commander& x) {
        x.event = j.at("event").get<std::string>();
        x.fid = j.at("FID").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const commander & x) {
        j = json::object();
        j["event"] = x.event;
        j["FID"] = x.fid;
        j["Name"] = x.name;
        j["timestamp"] = x.timestamp;
    }
}


