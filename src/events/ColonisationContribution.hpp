//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     colonisation_contribution data = nlohmann::json::parse(jsonString);

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

    struct contribution {
        int64_t amount;
        std::string name;
        std::string name_localised;
    };

    /**
     * When Written: when contributing materials to a colonisation effort
     */
    struct colonisation_contribution {
        std::vector<contribution> contributions;
        std::string event;
        int64_t market_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, contribution & x);
    void to_json(json & j, const contribution & x);

    void from_json(const json & j, colonisation_contribution & x);
    void to_json(json & j, const colonisation_contribution & x);

    inline void from_json(const json & j, contribution& x) {
        x.amount = j.at("Amount").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = j.at("Name_Localised").get<std::string>();
    }

    inline void to_json(json & j, const contribution & x) {
        j = json::object();
        j["Amount"] = x.amount;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, colonisation_contribution& x) {
        x.contributions = j.at("Contributions").get<std::vector<contribution>>();
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const colonisation_contribution & x) {
        j = json::object();
        j["Contributions"] = x.contributions;
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["timestamp"] = x.timestamp;
    }
}


