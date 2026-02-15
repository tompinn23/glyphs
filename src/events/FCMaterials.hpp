//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fc_materials data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct item {
        int64_t demand;
        int64_t id;
        std::string name;
        std::optional<std::string> name_localised;
        int64_t price;
        int64_t stock;
    };

    /**
     * When trading with a Fleet Carrier Bartender for materials, a file is written with the
     * pricelist to FCMaterials.json
     */
    struct fc_materials {
        std::string carrier_id;
        std::string carrier_name;
        std::string event;
        /**
         * Only included in FCMaterials.json
         */
        std::optional<std::vector<item>> items;
        int64_t market_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, item & x);
    void to_json(json & j, const item & x);

    void from_json(const json & j, fc_materials & x);
    void to_json(json & j, const fc_materials & x);

    inline void from_json(const json & j, item& x) {
        x.demand = j.at("Demand").get<int64_t>();
        x.id = j.at("id").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.price = j.at("Price").get<int64_t>();
        x.stock = j.at("Stock").get<int64_t>();
    }

    inline void to_json(json & j, const item & x) {
        j = json::object();
        j["Demand"] = x.demand;
        j["id"] = x.id;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Price"] = x.price;
        j["Stock"] = x.stock;
    }

    inline void from_json(const json & j, fc_materials& x) {
        x.carrier_id = j.at("CarrierID").get<std::string>();
        x.carrier_name = j.at("CarrierName").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.items = get_stack_optional<std::vector<item>>(j, "Items");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const fc_materials & x) {
        j = json::object();
        j["CarrierID"] = x.carrier_id;
        j["CarrierName"] = x.carrier_name;
        j["event"] = x.event;
        j["Items"] = x.items;
        j["MarketID"] = x.market_id;
        j["timestamp"] = x.timestamp;
    }
}


