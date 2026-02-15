//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fileheader data = nlohmann::json::parse(jsonString);

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

    struct fileheader {
        /**
         * Game build number
         */
        std::string build;
        std::string event;
        /**
         * Which version of the game produced the log (will indicate if beta)
         */
        std::string gameversion;
        /**
         * The language code
         */
        std::string language;
        /**
         * True for gameversions >= 4.0, both Horizons and Odyssey.
         */
        bool odyssey;
        /**
         * The file part number
         */
        int64_t part;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, fileheader & x);
    void to_json(json & j, const fileheader & x);

    inline void from_json(const json & j, fileheader& x) {
        x.build = j.at("build").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.gameversion = j.at("gameversion").get<std::string>();
        x.language = j.at("language").get<std::string>();
        x.odyssey = j.at("Odyssey").get<bool>();
        x.part = j.at("part").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const fileheader & x) {
        j = json::object();
        j["build"] = x.build;
        j["event"] = x.event;
        j["gameversion"] = x.gameversion;
        j["language"] = x.language;
        j["Odyssey"] = x.odyssey;
        j["part"] = x.part;
        j["timestamp"] = x.timestamp;
    }
}


