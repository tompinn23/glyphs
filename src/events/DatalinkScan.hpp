//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     datalink_scan data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when scanning a data link
     */
    struct datalink_scan {
        std::string event;
        /**
         * Message identifier from data link
         */
        std::string message;
        /**
         * Localized message from data link
         */
        std::optional<std::string> message_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, datalink_scan & x);
    void to_json(json & j, const datalink_scan & x);

    inline void from_json(const json & j, datalink_scan& x) {
        x.event = j.at("event").get<std::string>();
        x.message = j.at("Message").get<std::string>();
        x.message_localised = get_stack_optional<std::string>(j, "Message_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const datalink_scan & x) {
        j = json::object();
        j["event"] = x.event;
        j["Message"] = x.message;
        j["Message_Localised"] = x.message_localised;
        j["timestamp"] = x.timestamp;
    }
}


