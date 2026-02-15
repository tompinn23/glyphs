//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     book_dropship data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * This event is logged when signing up to fight at a recruitment desk
     */
    struct book_dropship {
        int64_t cost;
        std::string destination_location;
        std::string destination_system;
        std::string event;
        std::optional<bool> retreat;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, book_dropship & x);
    void to_json(json & j, const book_dropship & x);

    inline void from_json(const json & j, book_dropship& x) {
        x.cost = j.at("Cost").get<int64_t>();
        x.destination_location = j.at("DestinationLocation").get<std::string>();
        x.destination_system = j.at("DestinationSystem").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.retreat = get_stack_optional<bool>(j, "Retreat");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const book_dropship & x) {
        j = json::object();
        j["Cost"] = x.cost;
        j["DestinationLocation"] = x.destination_location;
        j["DestinationSystem"] = x.destination_system;
        j["event"] = x.event;
        j["Retreat"] = x.retreat;
        j["timestamp"] = x.timestamp;
    }
}


