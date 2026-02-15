//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     sell_organic_data data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct bio_datum {
        int64_t bonus;
        std::string genus;
        std::optional<std::string> genus_localised;
        std::string species;
        std::optional<std::string> species_localised;
        int64_t value;
        std::optional<std::string> variant;
        std::optional<std::string> variant_localised;
    };

    /**
     * This event records that a player has sold organic data (see ScanOrganic)
     */
    struct sell_organic_data {
        std::vector<bio_datum> bio_data;
        std::string event;
        int64_t market_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, bio_datum & x);
    void to_json(json & j, const bio_datum & x);

    void from_json(const json & j, sell_organic_data & x);
    void to_json(json & j, const sell_organic_data & x);

    inline void from_json(const json & j, bio_datum& x) {
        x.bonus = j.at("Bonus").get<int64_t>();
        x.genus = j.at("Genus").get<std::string>();
        x.genus_localised = get_stack_optional<std::string>(j, "Genus_Localised");
        x.species = j.at("Species").get<std::string>();
        x.species_localised = get_stack_optional<std::string>(j, "Species_Localised");
        x.value = j.at("Value").get<int64_t>();
        x.variant = get_stack_optional<std::string>(j, "Variant");
        x.variant_localised = get_stack_optional<std::string>(j, "Variant_Localised");
    }

    inline void to_json(json & j, const bio_datum & x) {
        j = json::object();
        j["Bonus"] = x.bonus;
        j["Genus"] = x.genus;
        j["Genus_Localised"] = x.genus_localised;
        j["Species"] = x.species;
        j["Species_Localised"] = x.species_localised;
        j["Value"] = x.value;
        j["Variant"] = x.variant;
        j["Variant_Localised"] = x.variant_localised;
    }

    inline void from_json(const json & j, sell_organic_data& x) {
        x.bio_data = j.at("BioData").get<std::vector<bio_datum>>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const sell_organic_data & x) {
        j = json::object();
        j["BioData"] = x.bio_data;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["timestamp"] = x.timestamp;
    }
}


