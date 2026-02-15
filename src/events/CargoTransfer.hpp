//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     cargo_transfer data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct transfer {
        int64_t count;
        std::string direction;
        std::optional<int64_t> mission_id;
        std::string type;
        std::optional<std::string> type_localised;
    };

    /**
     * When transferring cargo between ship and fleet carrier, or between ship and SRV
     */
    struct cargo_transfer {
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::vector<transfer> transfers;
    };
}

namespace hue {
    void from_json(const json & j, transfer & x);
    void to_json(json & j, const transfer & x);

    void from_json(const json & j, cargo_transfer & x);
    void to_json(json & j, const cargo_transfer & x);

    inline void from_json(const json & j, transfer& x) {
        x.count = j.at("Count").get<int64_t>();
        x.direction = j.at("Direction").get<std::string>();
        x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
        x.type = j.at("Type").get<std::string>();
        x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
    }

    inline void to_json(json & j, const transfer & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Direction"] = x.direction;
        j["MissionID"] = x.mission_id;
        j["Type"] = x.type;
        j["Type_Localised"] = x.type_localised;
    }

    inline void from_json(const json & j, cargo_transfer& x) {
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.transfers = j.at("Transfers").get<std::vector<transfer>>();
    }

    inline void to_json(json & j, const cargo_transfer & x) {
        j = json::object();
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["Transfers"] = x.transfers;
    }
}


