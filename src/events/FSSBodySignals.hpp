//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fss_body_signals data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;


    /**
     * This event is written when completing a Full Spectrum Scan of a starsystem, to list the
     * number of SAA signals found in the system (as shown in-game in the top-right panel)
     */
    struct fss_body_signals {
        int64_t body_id;
        std::string body_name;
        std::string event;
        std::vector<common::signal> signals;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {


    void from_json(const json & j, fss_body_signals & x);
    void to_json(json & j, const fss_body_signals & x);


    inline void from_json(const json & j, fss_body_signals& x) {
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_name = j.at("BodyName").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.signals = j.at("Signals").get<std::vector<common::signal>>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const fss_body_signals & x) {
        j = json::object();
        j["BodyID"] = x.body_id;
        j["BodyName"] = x.body_name;
        j["event"] = x.event;
        j["Signals"] = x.signals;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


