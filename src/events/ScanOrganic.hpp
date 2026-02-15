//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     scan_organic data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * This event is logged when the player uses the Organic Sampling Tool to scan, log or
     * analyse organic discoveries. The first scan is Log, subsequent scans are Sample until
     * fully scanned, final scan is Analyse
     */
    struct scan_organic {
        int64_t body;
        std::string event;
        std::string genus;
        std::optional<std::string> genus_localised;
        std::string scan_type;
        std::string species;
        std::optional<std::string> species_localised;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::optional<std::string> variant;
        std::optional<std::string> variant_localised;
        std::optional<bool> was_logged;
    };
}

namespace hue {
    void from_json(const json & j, scan_organic & x);
    void to_json(json & j, const scan_organic & x);

    inline void from_json(const json & j, scan_organic& x) {
        x.body = j.at("Body").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.genus = j.at("Genus").get<std::string>();
        x.genus_localised = get_stack_optional<std::string>(j, "Genus_Localised");
        x.scan_type = j.at("ScanType").get<std::string>();
        x.species = j.at("Species").get<std::string>();
        x.species_localised = get_stack_optional<std::string>(j, "Species_Localised");
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.variant = get_stack_optional<std::string>(j, "Variant");
        x.variant_localised = get_stack_optional<std::string>(j, "Variant_Localised");
        x.was_logged = get_stack_optional<bool>(j, "WasLogged");
    }

    inline void to_json(json & j, const scan_organic & x) {
        j = json::object();
        j["Body"] = x.body;
        j["event"] = x.event;
        j["Genus"] = x.genus;
        j["Genus_Localised"] = x.genus_localised;
        j["ScanType"] = x.scan_type;
        j["Species"] = x.species;
        j["Species_Localised"] = x.species_localised;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
        j["Variant"] = x.variant;
        j["Variant_Localised"] = x.variant_localised;
        j["WasLogged"] = x.was_logged;
    }
}


