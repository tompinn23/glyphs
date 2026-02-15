//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     crime_victim data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when another player commits a crime against the current player
     */
    struct crime_victim {
        /**
         * Fine or Bounty
         */
        std::optional<int64_t> bounty;
        std::string crime_type;
        std::string event;
        /**
         * Fine or Bounty
         */
        std::optional<int64_t> fine;
        std::string offender;
        std::optional<std::string> offender_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, crime_victim & x);
    void to_json(json & j, const crime_victim & x);

    inline void from_json(const json & j, crime_victim& x) {
        x.bounty = get_stack_optional<int64_t>(j, "Bounty");
        x.crime_type = j.at("CrimeType").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.fine = get_stack_optional<int64_t>(j, "Fine");
        x.offender = j.at("Offender").get<std::string>();
        x.offender_localised = get_stack_optional<std::string>(j, "Offender_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const crime_victim & x) {
        j = json::object();
        j["Bounty"] = x.bounty;
        j["CrimeType"] = x.crime_type;
        j["event"] = x.event;
        j["Fine"] = x.fine;
        j["Offender"] = x.offender;
        j["Offender_Localised"] = x.offender_localised;
        j["timestamp"] = x.timestamp;
    }
}


