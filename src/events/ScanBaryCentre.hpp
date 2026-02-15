//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     scan_bary_centre data = nlohmann::json::parse(jsonString);

#pragma once

#include "nlohmann/json.hpp"

namespace hue {
    using nlohmann::json;

    #ifndef NLOHMANN_UNTYPED_hue_HELPER
    #define NLOHMANN_UNTYPED_hue_HELPER
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    #endif

    /**
     * When scanning one body of a binary pair, you will get an event detailing the orbital
     * parameters of their BaryCentre
     */
    struct scan_bary_centre {
        double ascending_node;
        int64_t body_id;
        double eccentricity;
        std::string event;
        double mean_anomaly;
        double orbital_inclination;
        double orbital_period;
        double periapsis;
        double semi_major_axis;
        std::string star_system;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, scan_bary_centre & x);
    void to_json(json & j, const scan_bary_centre & x);

    inline void from_json(const json & j, scan_bary_centre& x) {
        x.ascending_node = j.at("AscendingNode").get<double>();
        x.body_id = j.at("BodyID").get<int64_t>();
        x.eccentricity = j.at("Eccentricity").get<double>();
        x.event = j.at("event").get<std::string>();
        x.mean_anomaly = j.at("MeanAnomaly").get<double>();
        x.orbital_inclination = j.at("OrbitalInclination").get<double>();
        x.orbital_period = j.at("OrbitalPeriod").get<double>();
        x.periapsis = j.at("Periapsis").get<double>();
        x.semi_major_axis = j.at("SemiMajorAxis").get<double>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const scan_bary_centre & x) {
        j = json::object();
        j["AscendingNode"] = x.ascending_node;
        j["BodyID"] = x.body_id;
        j["Eccentricity"] = x.eccentricity;
        j["event"] = x.event;
        j["MeanAnomaly"] = x.mean_anomaly;
        j["OrbitalInclination"] = x.orbital_inclination;
        j["OrbitalPeriod"] = x.orbital_period;
        j["Periapsis"] = x.periapsis;
        j["SemiMajorAxis"] = x.semi_major_axis;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


