//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     nav_route_clear data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: When the current plotted nav route is cleared. Can be written to
     * NavRoute.json with an empty Route array.
     */
    struct nav_route_clear {
        std::string event;
        std::optional<std::vector<std::map<std::string, nlohmann::json>>> route;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, nav_route_clear & x);
    void to_json(json & j, const nav_route_clear & x);

    inline void from_json(const json & j, nav_route_clear& x) {
        x.event = j.at("event").get<std::string>();
        x.route = get_stack_optional<std::vector<std::map<std::string, nlohmann::json>>>(j, "Route");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const nav_route_clear & x) {
        j = json::object();
        j["event"] = x.event;
        j["Route"] = x.route;
        j["timestamp"] = x.timestamp;
    }
}


