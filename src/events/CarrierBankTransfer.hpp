//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_bank_transfer data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * Player transfers credits to/from carrier
     */
    struct carrier_bank_transfer {
        /**
         * Carrier balance after transfer
         */
        int64_t carrier_balance;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::optional<int64_t> deposit;
        std::string event;
        /**
         * Player balance after transfer
         */
        int64_t player_balance;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<int64_t> withdraw;
    };
}

namespace hue {
    void from_json(const json & j, carrier_bank_transfer & x);
    void to_json(json & j, const carrier_bank_transfer & x);

    inline void from_json(const json & j, carrier_bank_transfer& x) {
        x.carrier_balance = j.at("CarrierBalance").get<int64_t>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.deposit = get_stack_optional<int64_t>(j, "Deposit");
        x.event = j.at("event").get<std::string>();
        x.player_balance = j.at("PlayerBalance").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.withdraw = get_stack_optional<int64_t>(j, "Withdraw");
    }

    inline void to_json(json & j, const carrier_bank_transfer & x) {
        j = json::object();
        j["CarrierBalance"] = x.carrier_balance;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["Deposit"] = x.deposit;
        j["event"] = x.event;
        j["PlayerBalance"] = x.player_balance;
        j["timestamp"] = x.timestamp;
        j["Withdraw"] = x.withdraw;
    }
}


