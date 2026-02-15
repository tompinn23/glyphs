//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     market data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct market_item {
        int64_t buy_price;
        std::string category;
        std::optional<std::string> category_localised;
        bool consumer;
        int64_t demand;
        int64_t demand_bracket;
        int64_t id;
        int64_t mean_price;
        std::string name;
        std::optional<std::string> name_localised;
        bool producer;
        bool rare;
        int64_t sell_price;
        int64_t stock;
        int64_t stock_bracket;
    };

    /**
     * When written: when accessing the commodity market in a station. A separate file
     * Market.json is written to the same folder as the journal, containing full market price
     * info.
     */
    struct market {
        std::optional<std::string> carrier_docking_access;
        std::string event;
        /**
         * When written to Market.json
         */
        std::optional<std::vector<market_item>> items;
        int64_t market_id;
        std::string star_system;
        std::string station_name;
        std::optional<std::string> station_name_localised;
        std::string station_type;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, market_item & x);
    void to_json(json & j, const market_item & x);

    void from_json(const json & j, market & x);
    void to_json(json & j, const market & x);

    inline void from_json(const json & j, market_item& x) {
        x.buy_price = j.at("BuyPrice").get<int64_t>();
        x.category = j.at("Category").get<std::string>();
        x.category_localised = get_stack_optional<std::string>(j, "Category_Localised");
        x.consumer = j.at("Consumer").get<bool>();
        x.demand = j.at("Demand").get<int64_t>();
        x.demand_bracket = j.at("DemandBracket").get<int64_t>();
        x.id = j.at("id").get<int64_t>();
        x.mean_price = j.at("MeanPrice").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.producer = j.at("Producer").get<bool>();
        x.rare = j.at("Rare").get<bool>();
        x.sell_price = j.at("SellPrice").get<int64_t>();
        x.stock = j.at("Stock").get<int64_t>();
        x.stock_bracket = j.at("StockBracket").get<int64_t>();
    }

    inline void to_json(json & j, const market_item & x) {
        j = json::object();
        j["BuyPrice"] = x.buy_price;
        j["Category"] = x.category;
        j["Category_Localised"] = x.category_localised;
        j["Consumer"] = x.consumer;
        j["Demand"] = x.demand;
        j["DemandBracket"] = x.demand_bracket;
        j["id"] = x.id;
        j["MeanPrice"] = x.mean_price;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Producer"] = x.producer;
        j["Rare"] = x.rare;
        j["SellPrice"] = x.sell_price;
        j["Stock"] = x.stock;
        j["StockBracket"] = x.stock_bracket;
    }

    inline void from_json(const json & j, market& x) {
        x.carrier_docking_access = get_stack_optional<std::string>(j, "CarrierDockingAccess");
        x.event = j.at("event").get<std::string>();
        x.items = get_stack_optional<std::vector<market_item>>(j, "Items");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_name = j.at("StationName").get<std::string>();
        x.station_name_localised = get_stack_optional<std::string>(j, "StationName_Localised");
        x.station_type = j.at("StationType").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const market & x) {
        j = json::object();
        j["CarrierDockingAccess"] = x.carrier_docking_access;
        j["event"] = x.event;
        j["Items"] = x.items;
        j["MarketID"] = x.market_id;
        j["StarSystem"] = x.star_system;
        j["StationName"] = x.station_name;
        j["StationName_Localised"] = x.station_name_localised;
        j["StationType"] = x.station_type;
        j["timestamp"] = x.timestamp;
    }
}


