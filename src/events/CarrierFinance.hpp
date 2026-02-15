//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_finance data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * Change to tax rate or reserve
     */
    struct carrier_finance {
        int64_t available_balance;
        int64_t carrier_balance;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string event;
        int64_t reserve_balance;
        int64_t reserve_percent;
        std::optional<int64_t> tax_rate;
        std::optional<int64_t> tax_rate_outfitting;
        std::optional<int64_t> tax_rate_pioneersupplies;
        std::optional<int64_t> tax_rate_rearm;
        std::optional<int64_t> tax_rate_refuel;
        std::optional<int64_t> tax_rate_repair;
        std::optional<int64_t> tax_rate_shipyard;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_finance & x);
    void to_json(json & j, const carrier_finance & x);

    inline void from_json(const json & j, carrier_finance& x) {
        x.available_balance = j.at("AvailableBalance").get<int64_t>();
        x.carrier_balance = j.at("CarrierBalance").get<int64_t>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.event = j.at("event").get<std::string>();
        x.reserve_balance = j.at("ReserveBalance").get<int64_t>();
        x.reserve_percent = j.at("ReservePercent").get<int64_t>();
        x.tax_rate = get_stack_optional<int64_t>(j, "TaxRate");
        x.tax_rate_outfitting = get_stack_optional<int64_t>(j, "TaxRate_outfitting");
        x.tax_rate_pioneersupplies = get_stack_optional<int64_t>(j, "TaxRate_pioneersupplies");
        x.tax_rate_rearm = get_stack_optional<int64_t>(j, "TaxRate_rearm");
        x.tax_rate_refuel = get_stack_optional<int64_t>(j, "TaxRate_refuel");
        x.tax_rate_repair = get_stack_optional<int64_t>(j, "TaxRate_repair");
        x.tax_rate_shipyard = get_stack_optional<int64_t>(j, "TaxRate_shipyard");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_finance & x) {
        j = json::object();
        j["AvailableBalance"] = x.available_balance;
        j["CarrierBalance"] = x.carrier_balance;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["event"] = x.event;
        j["ReserveBalance"] = x.reserve_balance;
        j["ReservePercent"] = x.reserve_percent;
        j["TaxRate"] = x.tax_rate;
        j["TaxRate_outfitting"] = x.tax_rate_outfitting;
        j["TaxRate_pioneersupplies"] = x.tax_rate_pioneersupplies;
        j["TaxRate_rearm"] = x.tax_rate_rearm;
        j["TaxRate_refuel"] = x.tax_rate_refuel;
        j["TaxRate_repair"] = x.tax_rate_repair;
        j["TaxRate_shipyard"] = x.tax_rate_shipyard;
        j["timestamp"] = x.timestamp;
    }
}


