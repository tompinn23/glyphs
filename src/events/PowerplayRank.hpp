//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     powerplay_rank data = nlohmann::json::parse(jsonString);

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

    /**
     * When written: when receiving salary payment from a power
     */
    struct powerplay_rank {
        std::string event;
        std::string power;
        int64_t rank;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, powerplay_rank & x);
    void to_json(json & j, const powerplay_rank & x);

    inline void from_json(const json & j, powerplay_rank& x) {
        x.event = j.at("event").get<std::string>();
        x.power = j.at("Power").get<std::string>();
        x.rank = j.at("Rank").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const powerplay_rank & x) {
        j = json::object();
        j["event"] = x.event;
        j["Power"] = x.power;
        j["Rank"] = x.rank;
        j["timestamp"] = x.timestamp;
    }
}


