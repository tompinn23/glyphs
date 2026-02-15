//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     srv_destroyed data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when the player's SRV is destroyed
     */
    struct srv_destroyed {
        std::string event;
        int64_t id;
        std::optional<std::string> srv_type;
        std::optional<std::string> srv_type_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, srv_destroyed & x);
    void to_json(json & j, const srv_destroyed & x);

    inline void from_json(const json & j, srv_destroyed& x) {
        x.event = j.at("event").get<std::string>();
        x.id = j.at("ID").get<int64_t>();
        x.srv_type = get_stack_optional<std::string>(j, "SRVType");
        x.srv_type_localised = get_stack_optional<std::string>(j, "SRVType_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const srv_destroyed & x) {
        j = json::object();
        j["event"] = x.event;
        j["ID"] = x.id;
        j["SRVType"] = x.srv_type;
        j["SRVType_Localised"] = x.srv_type_localised;
        j["timestamp"] = x.timestamp;
    }
}


