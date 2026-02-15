//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     nav_route data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct route_entry {
        std::string star_class;
        /**
         * star position, as a Json array [x, y, z], relative to Sol in Ly
         */
        std::vector<double> star_pos;
        std::string star_system;
        int64_t system_address;
    };

    /**
     * When plotting a multi-star route, the file NavRoute.json is written in the same directory
     * as the journal, with a list of stars along that route
     */
    struct nav_route {
        std::string event;
        std::optional<std::vector<route_entry>> route;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, route_entry & x);
    void to_json(json & j, const route_entry & x);

    void from_json(const json & j, nav_route & x);
    void to_json(json & j, const nav_route & x);

    inline void from_json(const json & j, route_entry& x) {
        x.star_class = j.at("StarClass").get<std::string>();
        x.star_pos = j.at("StarPos").get<std::vector<double>>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
    }

    inline void to_json(json & j, const route_entry & x) {
        j = json::object();
        j["StarClass"] = x.star_class;
        j["StarPos"] = x.star_pos;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
    }

    inline void from_json(const json & j, nav_route& x) {
        x.event = j.at("event").get<std::string>();
        x.route = get_stack_optional<std::vector<route_entry>>(j, "Route");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const nav_route & x) {
        j = json::object();
        j["event"] = x.event;
        j["Route"] = x.route;
        j["timestamp"] = x.timestamp;
    }
}


