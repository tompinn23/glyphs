//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     materials data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    namespace types {

        struct encoded {
            int64_t count;
            std::string name;
            /**
             * The localised value will be omitted if it is exactly the same as Name
             */
            std::optional<std::string> name_localised;
        };

        struct manufactured {
            int64_t count;
            std::string name;
            /**
             * The localised value will be omitted if it is exactly the same as Name
             */
            std::optional<std::string> name_localised;
        };

        struct raw {
            int64_t count;
            std::string name;
            /**
             * The localised value will be omitted if it is exactly the same as Name
             */
            std::optional<std::string> name_localised;
        };
    }

    /**
     * When written: at startup, when loading from main menu into game
     */
    struct materials {
        std::vector<types::encoded> encoded;
        std::string event;
        std::vector<types::manufactured> manufactured;
        std::vector<types::raw> raw;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    namespace types {

    inline void from_json(const json & j, encoded& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const encoded & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, manufactured& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const manufactured & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, raw& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const raw & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }
}

    inline void from_json(const json & j, materials& x) {
        x.encoded = j.at("Encoded").get<std::vector<types::encoded>>();
        x.event = j.at("event").get<std::string>();
        x.manufactured = j.at("Manufactured").get<std::vector<types::manufactured>>();
        x.raw = j.at("Raw").get<std::vector<types::raw>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const materials & x) {
        j = json::object();
        j["Encoded"] = x.encoded;
        j["event"] = x.event;
        j["Manufactured"] = x.manufactured;
        j["Raw"] = x.raw;
        j["timestamp"] = x.timestamp;
    }
}


