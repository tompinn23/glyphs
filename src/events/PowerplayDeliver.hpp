//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay_deliver data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when delivering powerplay commodities
     */
    struct powerplay_deliver {
        int64_t count;
        std::string event;
        std::string power;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
        std::optional<std::string> type_localised;
    };
}

namespace hue {
    void from_json(const json & j, powerplay_deliver & x);
    void to_json(json & j, const powerplay_deliver & x);

    inline void from_json(const json & j, powerplay_deliver& x) {
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.power = j.at("Power").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const powerplay_deliver & x) {
        j = json::object();
        j["Count"] = x.count;
        j["event"] = x.event;
        j["Power"] = x.power;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


