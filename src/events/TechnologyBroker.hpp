//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     technology_broker data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct commodity {
        int64_t count;
        std::string name;
        std::optional<std::string> name_localised;
    };

    struct unlocked_items {
        std::string name;
        std::optional<std::string> name_localised;
    };

    struct broker_material {
        std::string category;
        int64_t count;
        std::string name;
        std::optional<std::string> name_localised;
    };

    /**
     * When written: when using the Technology Broker to unlock new purchasable technology
     */
    struct technology_broker {
        std::string broker_type;
        std::vector<commodity> commodities;
        std::string event;
        std::vector<unlocked_items> items_unlocked;
        int64_t market_id;
        std::vector<broker_material> materials;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, commodity & x);
    void to_json(json & j, const commodity & x);

    void from_json(const json & j, unlocked_items & x);
    void to_json(json & j, const unlocked_items & x);

    void from_json(const json & j, broker_material& x);
    void to_json(json & j, const broker_material& x);

    void from_json(const json & j, technology_broker & x);
    void to_json(json & j, const technology_broker & x);

    inline void from_json(const json & j, commodity& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const commodity & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, unlocked_items& x) {
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const unlocked_items & x) {
        j = json::object();
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, broker_material& x) {
        x.category = j.at("Category").get<std::string>();
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const broker_material& x) {
        j = json::object();
        j["Category"] = x.category;
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, technology_broker& x) {
        x.broker_type = j.at("BrokerType").get<std::string>();
        x.commodities = j.at("Commodities").get<std::vector<commodity>>();
        x.event = j.at("event").get<std::string>();
        x.items_unlocked = j.at("ItemsUnlocked").get<std::vector<unlocked_items>>();
        x.market_id = j.at("MarketID").get<int64_t>();
        x.materials = j.at("Materials").get<std::vector<broker_material>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const technology_broker & x) {
        j = json::object();
        j["BrokerType"] = x.broker_type;
        j["Commodities"] = x.commodities;
        j["event"] = x.event;
        j["ItemsUnlocked"] = x.items_unlocked;
        j["MarketID"] = x.market_id;
        j["Materials"] = x.materials;
        j["timestamp"] = x.timestamp;
    }
}


