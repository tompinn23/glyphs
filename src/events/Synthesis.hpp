//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     synthesis data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct material {
        int64_t count;
        std::string name;
        std::optional<std::string> name_localised;
    };

    /**
     * When written: when synthesis is used to repair or rearm
     */
    struct synthesis {
        std::string event;
        /**
         * Materials used with quantities
         */
        std::vector<material> materials;
        /**
         * Synthesis blueprint
         */
        std::string name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, material & x);
    void to_json(json & j, const material & x);

    void from_json(const json & j, synthesis & x);
    void to_json(json & j, const synthesis & x);

    inline void from_json(const json & j, material& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const material & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, synthesis& x) {
        x.event = j.at("event").get<std::string>();
        x.materials = j.at("Materials").get<std::vector<material>>();
        x.name = j.at("Name").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const synthesis & x) {
        j = json::object();
        j["event"] = x.event;
        j["Materials"] = x.materials;
        j["Name"] = x.name;
        j["timestamp"] = x.timestamp;
    }
}


