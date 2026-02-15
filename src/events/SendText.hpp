//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     send_text data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when a text message is sent to another player
     */
    struct send_text {
        std::string event;
        std::string message;
        bool sent;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string to;
        /**
         * Unclear under which conditions this field is present, but it sometimes is.
         */
        std::optional<std::string> to_localised;
    };
}

namespace hue {
    void from_json(const json & j, send_text & x);
    void to_json(json & j, const send_text & x);

    inline void from_json(const json & j, send_text& x) {
        x.event = j.at("event").get<std::string>();
        x.message = j.at("Message").get<std::string>();
        x.sent = j.at("Sent").get<bool>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.to = j.at("To").get<std::string>();
        x.to_localised = get_stack_optional<std::string>(j, "To_Localised");
    }

    inline void to_json(json & j, const send_text & x) {
        j = json::object();
        j["event"] = x.event;
        j["Message"] = x.message;
        j["Sent"] = x.sent;
        j["timestamp"] = x.timestamp;
        j["To"] = x.to;
        j["To_Localised"] = x.to_localised;
    }
}


