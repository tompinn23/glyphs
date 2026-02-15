//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     cargo_depot data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when collecting or delivering cargo for a wing mission, or if a wing member
     * updates progress. The CargoType and Count are included when you collect or deliver goods,
     * they are not included for a wing update. The Progress value actually represents pending
     * progress for goods in transit: (ItemsCollected-ItemsDelivered)/TotalItemsToDeliver
     */
    struct cargo_depot {
        /**
         * Not included for UpdateType of WingUpdate
         */
        std::optional<std::string> cargo_type;
        std::optional<std::string> cargo_type_localised;
        /**
         * Not included for UpdateType of WingUpdate
         */
        std::optional<int64_t> count;
        int64_t end_market_id;
        std::string event;
        int64_t items_collected;
        int64_t items_delivered;
        int64_t mission_id;
        double progress;
        int64_t start_market_id;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t total_items_to_deliver;
        std::string update_type;
    };
}

namespace hue {
    void from_json(const json & j, cargo_depot & x);
    void to_json(json & j, const cargo_depot & x);

    inline void from_json(const json & j, cargo_depot& x) {
        x.cargo_type = get_stack_optional<std::string>(j, "CargoType");
        x.cargo_type_localised = get_stack_optional<std::string>(j, "CargoType_Localised");
        x.count = get_stack_optional<int64_t>(j, "Count");
        x.end_market_id = j.at("EndMarketID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.items_collected = j.at("ItemsCollected").get<int64_t>();
        x.items_delivered = j.at("ItemsDelivered").get<int64_t>();
        x.mission_id = j.at("MissionID").get<int64_t>();
        x.progress = j.at("Progress").get<double>();
        x.start_market_id = j.at("StartMarketID").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_items_to_deliver = j.at("TotalItemsToDeliver").get<int64_t>();
        x.update_type = j.at("UpdateType").get<std::string>();
    }

    inline void to_json(json & j, const cargo_depot & x) {
        j = json::object();
        j["CargoType"] = x.cargo_type;
        j["CargoType_Localised"] = x.cargo_type_localised;
        j["Count"] = x.count;
        j["EndMarketID"] = x.end_market_id;
        j["event"] = x.event;
        j["ItemsCollected"] = x.items_collected;
        j["ItemsDelivered"] = x.items_delivered;
        j["MissionID"] = x.mission_id;
        j["Progress"] = x.progress;
        j["StartMarketID"] = x.start_market_id;
        j["timestamp"] = x.timestamp;
        j["TotalItemsToDeliver"] = x.total_items_to_deliver;
        j["UpdateType"] = x.update_type;
    }
}


