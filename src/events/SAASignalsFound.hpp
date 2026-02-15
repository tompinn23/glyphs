//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     saa_signals_found data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct genus {
        std::string genus;
        std::optional<std::string> genus_localised;
    };



    /**
     * When written: when using Surface Area Analysis Scanner on a planet or rings
     */
    struct saa_signals_found {
        int64_t body_id;
        std::string body_name;
        std::string event;
        std::optional<std::vector<genus>> genuses;
        std::vector<common::signal> signals;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, genus & x);
    void to_json(json & j, const genus & x);

    void from_json(const json & j, saa_signals_found & x);
    void to_json(json & j, const saa_signals_found & x);

    inline void from_json(const json & j, genus& x) {
        x.genus = j.at("Genus").get<std::string>();
        x.genus_localised = get_stack_optional<std::string>(j, "Genus_Localised");
    }

    inline void to_json(json & j, const genus & x) {
        j = json::object();
        j["Genus"] = x.genus;
        j["Genus_Localised"] = x.genus_localised;
    }

    inline void from_json(const json & j, saa_signals_found& x) {
        x.body_id = j.at("BodyID").get<int64_t>();
        x.body_name = j.at("BodyName").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.genuses = get_stack_optional<std::vector<genus>>(j, "Genuses");
        x.signals = j.at("Signals").get<std::vector<common::signal>>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const saa_signals_found & x) {
        j = json::object();
        j["BodyID"] = x.body_id;
        j["BodyName"] = x.body_name;
        j["event"] = x.event;
        j["Genuses"] = x.genuses;
        j["Signals"] = x.signals;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


