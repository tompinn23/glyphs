//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     continued data = nlohmann::json::parse(jsonString);

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
     * When written: if the journal file grows to 500k lines, we write this event, close the
     * file, and start a new one. The new journalname will increase the partnumber, ex:
     * {datetime}.02.log. The new journal will start with a Fileheader and continue.
     */
    struct continued {
        std::string event;
        int64_t part;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, continued & x);
    void to_json(json & j, const continued & x);

    inline void from_json(const json & j, continued& x) {
        x.event = j.at("event").get<std::string>();
        x.part = j.at("Part").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const continued & x) {
        j = json::object();
        j["event"] = x.event;
        j["Part"] = x.part;
        j["timestamp"] = x.timestamp;
    }
}


