//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     uss_drop data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when dropping from Supercruise at a Unidentified Signal Source
     */
    struct uss_drop {
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t uss_threat;
        std::string uss_type;
        std::optional<std::string> uss_type_localised;
    };
}

namespace hue {
    void from_json(const json & j, uss_drop & x);
    void to_json(json & j, const uss_drop & x);

    inline void from_json(const json & j, uss_drop& x) {
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.uss_threat = j.at("USSThreat").get<int64_t>();
        x.uss_type = j.at("USSType").get<std::string>();
        x.uss_type_localised = get_stack_optional<std::string>(j, "USSType_Localised");
    }

    inline void to_json(json & j, const uss_drop & x) {
        j = json::object();
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["USSThreat"] = x.uss_threat;
        j["USSType"] = x.uss_type;
        j["USSType_Localised"] = x.uss_type_localised;
    }
}


