//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     passengers data = nlohmann::json::parse(jsonString);

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

    struct manifest_entry {
        int64_t count;
        int64_t mission_id;
        std::string type;
        bool vip;
        bool wanted;
    };

    /**
     * When written: at startup, when loading the saved game file
     */
    struct passengers {
        std::string event;
        /**
         * Array of passenger records
         */
        std::vector<manifest_entry> manifest;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, manifest_entry & x);
    void to_json(json & j, const manifest_entry & x);

    void from_json(const json & j, passengers & x);
    void to_json(json & j, const passengers & x);

    inline void from_json(const json & j, manifest_entry& x) {
        x.count = j.at("Count").get<int64_t>();
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.type = j.at("Type").get<std::string>();
        x.vip = j.at("VIP").get<bool>();
        x.wanted = j.at("Wanted").get<bool>();
    }

    inline void to_json(json & j, const manifest_entry & x) {
        j = json::object();
        j["Count"] = x.count;
        j["MissionID"] = x.mission_id;
        j["Type"] = x.type;
        j["VIP"] = x.vip;
        j["Wanted"] = x.wanted;
    }

    inline void from_json(const json & j, passengers& x) {
        x.event = j.at("event").get<std::string>();
        x.manifest = j.at("Manifest").get<std::vector<manifest_entry>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const passengers & x) {
        j = json::object();
        j["event"] = x.event;
        j["Manifest"] = x.manifest;
        j["timestamp"] = x.timestamp;
    }
}


