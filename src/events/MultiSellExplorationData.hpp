//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     multi_sell_exploration_data data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    namespace types {


        struct discovered {
            int64_t num_bodies;
            std::string system_name;
            /**
             * This field sometime appears in this event containing random data (bug)
             */
            std::optional<std::string> system_name_localised;
        };
    }

    /**
     * When written: when selling exploration data in Cartographics, a page at a time
     */
    struct multi_sell_exploration_data {
        int64_t base_value;
        int64_t bonus;
        std::vector<types::discovered> discovered;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        int64_t total_earnings;
    };
}

namespace hue {

    namespace types {
        inline void from_json(const json & j, discovered& x) {
            x.num_bodies = j.at("NumBodies").get<int64_t>();
            x.system_name = j.at("SystemName").get<std::string>();
            x.system_name_localised = get_stack_optional<std::string>(j, "SystemName_Localised");
        }

        inline void to_json(json & j, const discovered & x) {
            j = json::object();
            j["NumBodies"] = x.num_bodies;
            j["SystemName"] = x.system_name;
            j["SystemName_Localised"] = x.system_name_localised;
        }
    }

    inline void from_json(const json & j, multi_sell_exploration_data& x) {
        x.base_value = j.at("BaseValue").get<int64_t>();
        x.bonus = j.at("Bonus").get<int64_t>();
        x.discovered = j.at("Discovered").get<std::vector<types::discovered>>();
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.total_earnings = j.at("TotalEarnings").get<int64_t>();
    }

    inline void to_json(json & j, const multi_sell_exploration_data & x) {
        j = json::object();
        j["BaseValue"] = x.base_value;
        j["Bonus"] = x.bonus;
        j["Discovered"] = x.discovered;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
        j["TotalEarnings"] = x.total_earnings;
    }
}


