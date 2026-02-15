//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     pay_fines data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when paying fines
     */
    struct pay_fines {
        std::optional<bool> all_fines;
        /**
         * Total amount paid, including any broker fee
         */
        int64_t amount;
        /**
         * Present if paid via a broker
         */
        std::optional<double> broker_percentage;
        std::string event;
        /**
         * If paying off an individual faction's fines
         */
        std::optional<std::string> faction;
        /**
         * If paying off an individual faction's fines
         */
        std::optional<std::string> faction_localised;
        int64_t ship_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, pay_fines & x);
    void to_json(json & j, const pay_fines & x);

    inline void from_json(const json & j, pay_fines& x) {
        x.all_fines = get_stack_optional<bool>(j, "AllFines");
        x.amount = j.at("Amount").get<int64_t>();
        x.broker_percentage = get_stack_optional<double>(j, "BrokerPercentage");
        x.event = j.at("event").get<std::string>();
        x.faction = get_stack_optional<std::string>(j, "Faction");
        x.faction_localised = get_stack_optional<std::string>(j, "Faction_Localised");
        x.ship_id = j.at("ShipID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const pay_fines & x) {
        j = json::object();
        j["AllFines"] = x.all_fines;
        j["Amount"] = x.amount;
        j["BrokerPercentage"] = x.broker_percentage;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["Faction_Localised"] = x.faction_localised;
        j["ShipID"] = x.ship_id;
        j["timestamp"] = x.timestamp;
    }
}


