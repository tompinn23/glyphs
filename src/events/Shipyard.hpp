//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     shipyard data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct prices {
        int64_t id;
        int64_t ship_price;
        std::string ship_type;
        std::optional<std::string> ship_type_localised;
    };

    /**
     * When written: when accessing shipyard in a station. The full price list is written to a
     * separate file, in the same folder as the journal, Shipyard.json
     */
    struct shipyard {
        /**
         * Only written in Shipyard.json
         */
        std::optional<bool> allow_cobra_mk_iv;
        std::string event;
        /**
         * Only written in Shipyard.json
         */
        std::optional<bool> horizons;
        int64_t market_id;
        /**
         * Only written in Shipyard.json
         */
        std::optional<std::vector<prices>> price_list;
        std::string star_system;
        std::string station_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, prices & x);
    void to_json(json & j, const prices & x);

    void from_json(const json & j, shipyard & x);
    void to_json(json & j, const shipyard & x);

    inline void from_json(const json & j, prices& x) {
        x.id = j.at("id").get<int64_t>();
        x.ship_price = j.at("ShipPrice").get<int64_t>();
        x.ship_type = j.at("ShipType").get<std::string>();
        x.ship_type_localised = get_stack_optional<std::string>(j, "ShipType_Localised");
    }

    inline void to_json(json & j, const prices & x) {
        j = json::object();
        j["id"] = x.id;
        j["ShipPrice"] = x.ship_price;
        j["ShipType"] = x.ship_type;
        j["ShipType_Localised"] = x.ship_type_localised;
    }

    inline void from_json(const json & j, shipyard& x) {
        x.allow_cobra_mk_iv = get_stack_optional<bool>(j, "AllowCobraMkIV");
        x.event = j.at("event").get<std::string>();
        x.horizons = get_stack_optional<bool>(j, "Horizons");
        x.market_id = j.at("MarketID").get<int64_t>();
        x.price_list = get_stack_optional<std::vector<prices>>(j, "PriceList");
        x.star_system = j.at("StarSystem").get<std::string>();
        x.station_name = j.at("StationName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const shipyard & x) {
        j = json::object();
        j["AllowCobraMkIV"] = x.allow_cobra_mk_iv;
        j["event"] = x.event;
        j["Horizons"] = x.horizons;
        j["MarketID"] = x.market_id;
        j["PriceList"] = x.price_list;
        j["StarSystem"] = x.star_system;
        j["StationName"] = x.station_name;
        j["timestamp"] = x.timestamp;
    }
}


