//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     cargo data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    namespace types {

        struct inventory {
            int64_t count;
            std::optional<int64_t> mission_id;
            std::string name;
            std::optional<std::string> name_localised;
            int64_t stolen;
        };
    }

    /**
     * When written: at startup, note this is now written slightly later in startup, after we
     * have initialised missions, so we can detect if any cargo came from an abandoned delivery
     * mission. The first Cargo event in the file will contain the full inventory, others just
     * indicate a separate file has been written. The full data is now written to a separate
     * file Cargo.json. A simple event (with no parameters) is written to the main journal file
     * when the cargo file is updated.
     */
    struct cargo {
        int64_t count;
        std::string event;
        std::optional<std::vector<types::inventory>> inventory;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string vessel;
    };
}

namespace hue {
    namespace types {

        inline void from_json(const json & j, inventory& x) {
            x.count = j.at("Count").get<int64_t>();
            x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
            x.name = j.at("Name").get<std::string>();
            x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
            x.stolen = j.at("Stolen").get<int64_t>();
        }

        inline void to_json(json & j, const inventory & x) {
            j = json::object();
            j["Count"] = x.count;
            j["MissionID"] = x.mission_id;
            j["Name"] = x.name;
            j["Name_Localised"] = x.name_localised;
            j["Stolen"] = x.stolen;
        }
    }
    inline void from_json(const json & j, cargo& x) {
        x.count = j.at("Count").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.inventory = get_stack_optional<std::vector<types::inventory>>(j, "Inventory");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.vessel = j.at("Vessel").get<std::string>();
    }

    inline void to_json(json & j, const cargo & x) {
        j = json::object();
        j["Count"] = x.count;
        j["event"] = x.event;
        j["Inventory"] = x.inventory;
        j["timestamp"] = x.timestamp;
        j["Vessel"] = x.vessel;
    }
}


