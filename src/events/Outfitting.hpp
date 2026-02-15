//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     outfitting data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct outfitting_item {
        int64_t buy_price;
        int64_t id;
        std::string name;
    };

    /**
     * Written when accessing the outfitting menu. The full parts pricelist is written to a
     * separate file Outfitting.json.
     */
    struct outfitting {
        std::string event;
        /**
         * Only written in Outfitting.json
         */
        std::optional<bool> horizons;
        /**
         * Only written in Outfitting.json
         */
        std::optional<std::vector<outfitting_item>> items;
        int64_t market_id;
        std::string star_system;
        std::string station_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, outfitting_item & x);
    void to_json(json & j, const outfitting_item & x);

    void from_json(const json & j, outfitting & x);
    void to_json(json & j, const outfitting & x);

    inline void from_json(const json & j, outfitting_item& x) {
        x.buy_price = j.at("BuyPrice").get<int64_t>();
        x.id = j.at("id").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
    }

    inline void to_json(json & j, const outfitting_item & x) {
        j = json::object();
        j["BuyPrice"] = x.buy_price;
        j["id"] = x.id;
        j["Name"] = x.name;
    }

    inline void from_json(const json & j, outfitting& x) {
        x.event = j.at("event").get<std::string>();
        x.horizons = get_stack_optional<bool>(j, "Horizons");
        x.items = get_stack_optional<std::vector<outfitting_item>>(j, "Items");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_name = j.at("StationName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const outfitting & x) {
        j = json::object();
        j["event"] = x.event;
        j["Horizons"] = x.horizons;
        j["Items"] = x.items;
        j["MarketID"] = x.market_id;
        j["StarSystem"] = x.star_system;
        j["StationName"] = x.station_name;
        j["timestamp"] = x.timestamp;
    }
}


