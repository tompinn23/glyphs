//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     material_discovered data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When Written: when a new material is discovered
     */
    struct material_discovered {
        std::string category;
        int64_t discovery_number;
        std::string event;
        std::string name;
        /**
         * The localised value will be omitted if it is exactly the same as Name
         */
        std::optional<std::string> name_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, material_discovered & x);
    void to_json(json & j, const material_discovered & x);

    inline void from_json(const json & j, material_discovered& x) {
        x.category = j.at("Category").get<std::string>();
        x.discovery_number = j.at("DiscoveryNumber").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const material_discovered & x) {
        j = json::object();
        j["Category"] = x.category;
        j["DiscoveryNumber"] = x.discovery_number;
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["timestamp"] = x.timestamp;
    }
}


