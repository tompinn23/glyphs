//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     transfer_micro_resources data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct micro_transfer {
        std::string category;
        std::string direction;
        int64_t locker_new_count;
        int64_t locker_old_count;
        std::string name;
        std::optional<std::string> name_localised;
    };

    /**
     * Written when transferring items between backpack and ship locker
     */
    struct transfer_micro_resources {
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::vector<micro_transfer> transfers;
    };
}

namespace hue {
    void from_json(const json & j, micro_transfer& x);
    void to_json(json & j, const micro_transfer& x);

    void from_json(const json & j, transfer_micro_resources & x);
    void to_json(json & j, const transfer_micro_resources & x);

    inline void from_json(const json & j, micro_transfer& x) {
        x.category = j.at("Category").get<std::string>();
        x.direction = j.at("Direction").get<std::string>();
        x.locker_new_count = j.at("LockerNewCount").get<int64_t>();
        x.locker_old_count = j.at("LockerOldCount").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const micro_transfer& x) {
        j = json::object();
        j["Category"] = x.category;
        j["Direction"] = x.direction;
        j["LockerNewCount"] = x.locker_new_count;
        j["LockerOldCount"] = x.locker_old_count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, transfer_micro_resources& x) {
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.transfers = j.at("Transfers").get<std::vector<micro_transfer>>();
    }

    inline void to_json(json & j, const transfer_micro_resources & x) {
        j = json::object();
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["Transfers"] = x.transfers;
    }
}


