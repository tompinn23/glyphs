//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     colonisation_construction_depot data = nlohmann::json::parse(jsonString);

#pragma once

#include "nlohmann/json.hpp"

namespace hue {
    using nlohmann::json;

    #ifndef NLOHMANN_UNTYPED_hue_HELPER
    #define NLOHMANN_UNTYPED_hue_HELPER
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    #endif

    namespace types {
    struct resources_required {
        std::string name;
        std::string name_localised;
        int64_t payment;
        int64_t provided_amount;
        int64_t required_amount;
    };
}

    /**
     * When Written: Every 15 seconds while docked at a construction depot
     */
    struct colonisation_construction_depot {
        bool construction_complete;
        bool construction_failed;
        double construction_progress;
        std::string event;
        int64_t market_id;
        std::vector<types::resources_required> resources_required;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {

    namespace types {

    inline void from_json(const json & j, resources_required& x) {
        x.name = j.at("Name").get<std::string>();
        x.name_localised = j.at("Name_Localised").get<std::string>();
        x.payment = j.at("Payment").get<int64_t>();
        x.provided_amount = j.at("ProvidedAmount").get<int64_t>();
        x.required_amount = j.at("RequiredAmount").get<int64_t>();
    }

    inline void to_json(json & j, const resources_required & x) {
        j = json::object();
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Payment"] = x.payment;
        j["ProvidedAmount"] = x.provided_amount;
        j["RequiredAmount"] = x.required_amount;
    }
}

    inline void from_json(const json & j, colonisation_construction_depot& x) {
        x.construction_complete = j.at("ConstructionComplete").get<bool>();
        x.construction_failed = j.at("ConstructionFailed").get<bool>();
        x.construction_progress = j.at("ConstructionProgress").get<double>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.resources_required = j.at("ResourcesRequired").get<std::vector<types::resources_required>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const colonisation_construction_depot & x) {
        j = json::object();
        j["ConstructionComplete"] = x.construction_complete;
        j["ConstructionFailed"] = x.construction_failed;
        j["ConstructionProgress"] = x.construction_progress;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["ResourcesRequired"] = x.resources_required;
        j["timestamp"] = x.timestamp;
    }
}


