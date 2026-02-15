//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_trade_order data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * The carrier owner has requested the carrier buys or sells goods (or cancels such an order)
     */
    struct carrier_trade_order {
        bool black_market;
        /**
         * PurchaseOrder or SaleOrder or CancelTrade
         */
        std::optional<bool> cancel_trade;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::string commodity;
        std::optional<std::string> commodity_localised;
        std::string event;
        std::optional<int64_t> price;
        /**
         * PurchaseOrder or SaleOrder or CancelTrade
         */
        std::optional<int64_t> purchase_order;
        /**
         * PurchaseOrder or SaleOrder or CancelTrade
         */
        std::optional<int64_t> sale_order;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_trade_order & x);
    void to_json(json & j, const carrier_trade_order & x);

    inline void from_json(const json & j, carrier_trade_order& x) {
        x.black_market = j.at("BlackMarket").get<bool>();
        x.cancel_trade = get_stack_optional<bool>(j, "CancelTrade");
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.commodity = j.at("Commodity").get<std::string>();
        x.commodity_localised = get_stack_optional<std::string>(j, "Commodity_Localised");
        x.event = j.at("event").get<std::string>();
        x.price = get_stack_optional<int64_t>(j, "Price");
        x.purchase_order = get_stack_optional<int64_t>(j, "PurchaseOrder");
        x.sale_order = get_stack_optional<int64_t>(j, "SaleOrder");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_trade_order & x) {
        j = json::object();
        j["BlackMarket"] = x.black_market;
        j["CancelTrade"] = x.cancel_trade;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["Commodity"] = x.commodity;
        j["Commodity_Localised"] = x.commodity_localised;
        j["event"] = x.event;
        j["Price"] = x.price;
        j["PurchaseOrder"] = x.purchase_order;
        j["SaleOrder"] = x.sale_order;
        j["timestamp"] = x.timestamp;
    }
}


