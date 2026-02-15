//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     redeem_voucher data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct voucher_faction {
        int64_t amount;
        std::string faction;
    };

    /**
     * When Written: when claiming payment for combat bounties and bonds
     */
    struct redeem_voucher {
        /**
         * Net amount received, after any broker fee
         */
        int64_t amount;
        std::optional<double> broker_percentage;
        std::string event;
        std::optional<std::string> faction;
        /**
         * For type bounty
         */
        std::optional<std::vector<voucher_faction>> factions;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string type;
    };
}

namespace hue {
    void from_json(const json & j, voucher_faction & x);
    void to_json(json & j, const voucher_faction & x);

    void from_json(const json & j, redeem_voucher & x);
    void to_json(json & j, const redeem_voucher & x);

    inline void from_json(const json & j, voucher_faction& x) {
        x.amount = j.at("Amount").get<int64_t>();
        x.faction = j.at("Faction").get<std::string>();
    }

    inline void to_json(json & j, const voucher_faction & x) {
        j = json::object();
        j["Amount"] = x.amount;
        j["Faction"] = x.faction;
    }

    inline void from_json(const json & j, redeem_voucher& x) {
        x.amount = j.at("Amount").get<int64_t>();
        x.broker_percentage = get_stack_optional<double>(j, "BrokerPercentage");
        x.event = j.at("event").get<std::string>();
        x.faction = get_stack_optional<std::string>(j, "Faction");
        x.factions = get_stack_optional<std::vector<voucher_faction>>(j, "Factions");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.type = j.at("Type").get<std::string>();
    }

    inline void to_json(json & j, const redeem_voucher & x) {
        j = json::object();
        j["Amount"] = x.amount;
        j["BrokerPercentage"] = x.broker_percentage;
        j["event"] = x.event;
        j["Faction"] = x.faction;
        j["Factions"] = x.factions;
        j["timestamp"] = x.timestamp;
        j["Type"] = x.type;
    }
}


