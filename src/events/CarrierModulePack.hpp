//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_module_pack data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct carrier_module_pack {
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::optional<int64_t> cost;
        std::string event;
        std::string operation;
        std::string pack_theme;
        int64_t pack_tier;
        std::optional<int64_t> refund;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, carrier_module_pack & x);
    void to_json(json & j, const carrier_module_pack & x);

    inline void from_json(const json & j, carrier_module_pack& x) {
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.cost = get_stack_optional<int64_t>(j, "Cost");
        x.event = j.at("event").get<std::string>();
        x.operation = j.at("Operation").get<std::string>();
        x.pack_theme = j.at("PackTheme").get<std::string>();
        x.pack_tier = j.at("PackTier").get<int64_t>();
        x.refund = get_stack_optional<int64_t>(j, "Refund");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_module_pack & x) {
        j = json::object();
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["Cost"] = x.cost;
        j["event"] = x.event;
        j["Operation"] = x.operation;
        j["PackTheme"] = x.pack_theme;
        j["PackTier"] = x.pack_tier;
        j["Refund"] = x.refund;
        j["timestamp"] = x.timestamp;
    }
}


