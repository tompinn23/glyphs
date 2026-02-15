//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     cancel_dropship data = nlohmann::json::parse(jsonString);

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
     * This event is logged if the player cancels their journey to a combat zone
     */
    struct cancel_dropship {
        std::string event;
        int64_t refund;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, cancel_dropship & x);
    void to_json(json & j, const cancel_dropship & x);

    inline void from_json(const json & j, cancel_dropship& x) {
        x.event = j.at("event").get<std::string>();
        x.refund = j.at("Refund").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const cancel_dropship & x) {
        j = json::object();
        j["event"] = x.event;
        j["Refund"] = x.refund;
        j["timestamp"] = x.timestamp;
    }
}


