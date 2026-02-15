//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     clear_saved_game data = nlohmann::json::parse(jsonString);

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
     * When written: If you should ever reset your game
     */
    struct clear_saved_game {
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
    void from_json(const json & j, clear_saved_game & x);
    void to_json(json & j, const clear_saved_game & x);

    inline void from_json(const json & j, clear_saved_game& x) {
        x.event = j.at("event").get<std::string>();
        x.fid = j.at("FID").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const clear_saved_game & x) {
        j = json::object();
        j["event"] = x.event;
        j["FID"] = x.fid;
        j["Name"] = x.name;
        j["timestamp"] = x.timestamp;
    }
}


