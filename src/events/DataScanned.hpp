//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     data_scanned data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when scanning some types of data links
     */
    struct data_scanned {
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
        std::optional<std::string> type_localised;
    };
}

namespace hue {
    void from_json(const json & j, data_scanned & x);
    void to_json(json & j, const data_scanned & x);

    inline void from_json(const json & j, data_scanned& x) {
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const data_scanned & x) {
        j = json::object();
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }
}


