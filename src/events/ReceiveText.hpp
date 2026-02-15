//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     receive_text data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when a text message is received from another player or npc
     */
    struct receive_text {
        std::string channel;
        std::string event;
        std::string from;
        std::optional<std::string> from_localised;
        std::string message;
        std::optional<std::string> message_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, receive_text & x);
    void to_json(json & j, const receive_text & x);

    inline void from_json(const json & j, receive_text& x) {
        x.channel = j.at("Channel").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.from = j.at("From").get<std::string>();
        x.from_localised = get_stack_optional<std::string>(j, "From_Localised");
        x.message = j.at("Message").get<std::string>();
        x.message_localised = get_stack_optional<std::string>(j, "Message_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const receive_text & x) {
        j = json::object();
        j["Channel"] = x.channel;
        j["event"] = x.event;
        j["From"] = x.from;
        j["From_Localised"] = x.from_localised;
        j["Message"] = x.message;
        j["Message_Localised"] = x.message_localised;
        j["timestamp"] = x.timestamp;
    }
}


