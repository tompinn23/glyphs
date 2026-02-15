//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     missions data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;


    namespace types {
        struct active {
        /**
         * Time left in seconds
         */
        int64_t expires;
        int64_t mission_id;
        std::string name;
        std::optional<std::string> name_localised;
        bool passenger_mission;
    };

    struct complete {
        /**
         * Time left in seconds
         */
        int64_t expires;
        int64_t mission_id;
        std::string name;
        std::optional<std::string> name_localised;
        bool passenger_mission;
    };

    struct failed {
        /**
         * Time left in seconds
         */
        int64_t expires;
        int64_t mission_id;
        std::string name;
        std::optional<std::string> name_localised;
        bool passenger_mission;
    };
    }

    /**
     * When written: at startup
     */
    struct missions {
        std::vector<types::active> active;
        std::vector<types::complete> complete;
        std::string event;
        std::vector<types::failed> failed;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    namespace types {
    inline void from_json(const json & j, active& x) {
        x.expires = j.at("Expires").get<int64_t>();
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.passenger_mission = j.at("PassengerMission").get<bool>();
    }

    inline void to_json(json & j, const active & x) {
        j = json::object();
        j["Expires"] = x.expires;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["PassengerMission"] = x.passenger_mission;
    }

    inline void from_json(const json & j, complete& x) {
        x.expires = j.at("Expires").get<int64_t>();
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.passenger_mission = j.at("PassengerMission").get<bool>();
    }

    inline void to_json(json & j, const complete & x) {
        j = json::object();
        j["Expires"] = x.expires;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["PassengerMission"] = x.passenger_mission;
    }

    inline void from_json(const json & j, failed& x) {
        x.expires = j.at("Expires").get<int64_t>();
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.passenger_mission = j.at("PassengerMission").get<bool>();
    }

    inline void to_json(json & j, const failed & x) {
        j = json::object();
        j["Expires"] = x.expires;
        j["MissionID"] = x.mission_id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["PassengerMission"] = x.passenger_mission;
    }
    }

    void from_json(const json & j, missions & x);
    void to_json(json & j, const missions & x);



    inline void from_json(const json & j, missions& x) {
        x.active = j.at("Active").get<std::vector<types::active>>();
        x.complete = j.at("Complete").get<std::vector<types::complete>>();
        x.event = j.at("event").get<std::string>();
        x.failed = j.at("Failed").get<std::vector<types::failed>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const missions & x) {
        j = json::object();
        j["Active"] = x.active;
        j["Complete"] = x.complete;
        j["event"] = x.event;
        j["Failed"] = x.failed;
        j["timestamp"] = x.timestamp;
    }
}


