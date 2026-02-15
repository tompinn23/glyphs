//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     material_trade data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    namespace types {

    struct paid {
        std::string category;
        std::string material;
        /**
         * The localised value will be omitted if it is exactly the same as Material
         */
        std::optional<std::string> material_localised;
        int64_t quantity;
    };

    struct received {
        std::string category;
        std::string material;
        /**
         * The localised value will be omitted if it is exactly the same as Material
         */
        std::optional<std::string> material_localised;
        int64_t quantity;
    };
}

    /**
     * When written: when exchanging materials at the Material trader contact
     */
    struct material_trade {
        std::string event;
        int64_t market_id;
        types::paid paid;
        types::received received;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        std::string trader_type;
    };
}

namespace hue {
    namespace types {

        inline void from_json(const json & j, paid& x) {
            x.category = j.at("Category").get<std::string>();
            x.material = j.at("Material").get<std::string>();
            x.material_localised = get_stack_optional<std::string>(j, "Material_Localised");
            x.quantity = j.at("Quantity").get<int64_t>();
        }

        inline void to_json(json & j, const paid & x) {
            j = json::object();
            j["Category"] = x.category;
            j["Material"] = x.material;
            j["Material_Localised"] = x.material_localised;
            j["Quantity"] = x.quantity;
        }

        inline void from_json(const json & j, received& x) {
            x.category = j.at("Category").get<std::string>();
            x.material = j.at("Material").get<std::string>();
            x.material_localised = get_stack_optional<std::string>(j, "Material_Localised");
            x.quantity = j.at("Quantity").get<int64_t>();
        }

        inline void to_json(json & j, const received & x) {
            j = json::object();
            j["Category"] = x.category;
            j["Material"] = x.material;
            j["Material_Localised"] = x.material_localised;
            j["Quantity"] = x.quantity;
        }
    }

    inline void from_json(const json & j, material_trade& x) {
        x.event = j.at("event").get<std::string>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.paid = j.at("Paid").get<types::paid>();
        x.received = j.at("Received").get<types::received>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.trader_type = j.at("TraderType").get<std::string>();
    }

    inline void to_json(json & j, const material_trade & x) {
        j = json::object();
        j["event"] = x.event;
        j["MarketID"] = x.market_id;
        j["Paid"] = x.paid;
        j["Received"] = x.received;
        j["timestamp"] = x.timestamp;
        j["TraderType"] = x.trader_type;
    }
}


