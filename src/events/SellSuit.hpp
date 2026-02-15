//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     sell_suit data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * This event is logged when a player sells a flight suit
     */
    struct sell_suit {
        std::string event;
        std::string name;
        std::optional<std::string> name_localised;
        int64_t price;
        int64_t suit_id;
        std::vector<std::string> suit_mods;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, sell_suit & x);
    void to_json(json & j, const sell_suit & x);

    inline void from_json(const json & j, sell_suit& x) {
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.price = j.at("Price").get<int64_t>();
        x.suit_id = j.at("SuitID").get<int64_t>();
        x.suit_mods = j.at("SuitMods").get<std::vector<std::string>>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const sell_suit & x) {
        j = json::object();
        j["event"] = x.event;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Price"] = x.price;
        j["SuitID"] = x.suit_id;
        j["SuitMods"] = x.suit_mods;
        j["timestamp"] = x.timestamp;
    }
}


