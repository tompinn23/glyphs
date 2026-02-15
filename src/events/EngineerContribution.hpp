//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     engineer_contribution data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when offering items cash or bounties to an Engineer to gain access
     */
    struct engineer_contribution {
        std::optional<std::string> commodity;
        std::optional<std::string> commodity_localised;
        std::string engineer;
        int64_t engineer_id;
        std::string event;
        std::optional<std::string> material;
        std::optional<std::string> material_localised;
        /**
         * Quantity offered this time
         */
        int64_t quantity;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * Total amount donated
         */
        int64_t total_quantity;
        std::string type;
    };
}

namespace hue {
    void from_json(const json & j, engineer_contribution & x);
    void to_json(json & j, const engineer_contribution & x);

    inline void from_json(const json & j, engineer_contribution& x) {
        x.commodity = get_stack_optional<std::string>(j, "Commodity");
        x.commodity_localised = get_stack_optional<std::string>(j, "Commodity_Localised");
        x.engineer = j.at("Engineer").get<std::string>();
        x.engineer_id = j.at("EngineerID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.material = get_stack_optional<std::string>(j, "Material");
        x.material_localised = get_stack_optional<std::string>(j, "Material_Localised");
        x.quantity = j.at("Quantity").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_quantity = j.at("TotalQuantity").get<int64_t>();
        x.type = j.at("Type").get<std::string>();
    }

    inline void to_json(json & j, const engineer_contribution & x) {
        j = json::object();
        j["Commodity"] = x.commodity;
        j["Commodity_Localised"] = x.commodity_localised;
        j["Engineer"] = x.engineer;
        j["EngineerID"] = x.engineer_id;
        j["event"] = x.event;
        j["Material"] = x.material;
        j["Material_Localised"] = x.material_localised;
        j["Quantity"] = x.quantity;
        j["timestamp"] = x.timestamp;
        j["TotalQuantity"] = x.total_quantity;
        j["Type"] = x.type;
    }
}


