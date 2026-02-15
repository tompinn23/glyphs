//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     screenshot data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when a screen snapshot is saved. The latitude, longitude, altitude and
     * heading will be included if on a planet or in low-altitude flight.
     */
    struct screenshot {
        std::optional<double> altitude;
        std::optional<std::string> body;
        std::string event;
        /**
         * Filename of screenshot
         */
        std::string filename;
        std::optional<int64_t> heading;
        int64_t height;
        std::optional<double> latitude;
        std::optional<double> longitude;
        std::optional<std::string> system;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t width;
    };
}

namespace hue {
    void from_json(const json & j, screenshot & x);
    void to_json(json & j, const screenshot & x);

    inline void from_json(const json & j, screenshot& x) {
        x.altitude = get_stack_optional<double>(j, "Altitude");
        x.body = get_stack_optional<std::string>(j, "Body");
        x.event = j.at("event").get<std::string>();
        x.filename = j.at("Filename").get<std::string>();
        x.heading = get_stack_optional<int64_t>(j, "Heading");
        x.height = j.at("Height").get<int64_t>();
        x.latitude = get_stack_optional<double>(j, "Latitude");
        x.longitude = get_stack_optional<double>(j, "Longitude");
        x.system = get_stack_optional<std::string>(j, "System");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.width = j.at("Width").get<int64_t>();
    }

    inline void to_json(json & j, const screenshot & x) {
        j = json::object();
        j["Altitude"] = x.altitude;
        j["Body"] = x.body;
        j["event"] = x.event;
        j["Filename"] = x.filename;
        j["Heading"] = x.heading;
        j["Height"] = x.height;
        j["Latitude"] = x.latitude;
        j["Longitude"] = x.longitude;
        j["System"] = x.system;
        j["timestamp"] = x.timestamp;
        j["Width"] = x.width;
    }
}


