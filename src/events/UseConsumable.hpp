//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     use_consumable data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When using an item from the playerΓÇÖs inventory (backpack)
     */
    struct use_consumable {
        std::string event;
        std::string name;
        std::optional<std::string> name_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
    };
}

namespace hue {
    void from_json(const json & j, use_consumable & x);
    void to_json(json & j, const use_consumable & x);

    inline void from_json(const json & j, use_consumable& x) {
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
    }

    inline void to_json(json & j, const use_consumable & x) {
        j = json::object();
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
    }
}


