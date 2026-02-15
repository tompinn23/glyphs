//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     squadron_startup data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct squadron_startup {
        int64_t current_rank;
        std::optional<std::string> current_rank_name;
        std::optional<std::string> current_rank_name_localised;
        std::string event;
        std::optional<int64_t> squadron_id;
        std::string squadron_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, squadron_startup & x);
    void to_json(json & j, const squadron_startup & x);

    inline void from_json(const json & j, squadron_startup& x) {
        x.current_rank = j.at("CurrentRank").get<int64_t>();
        x.current_rank_name = get_stack_optional<std::string>(j, "CurrentRankName");
        x.current_rank_name_localised = get_stack_optional<std::string>(j, "CurrentRankName_Localised");
        x.event = j.at("event").get<std::string>();
        x.squadron_id = get_stack_optional<int64_t>(j, "SquadronID");
        x.squadron_name = j.at("SquadronName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const squadron_startup & x) {
        j = json::object();
        j["CurrentRank"] = x.current_rank;
        j["CurrentRankName"] = x.current_rank_name;
        j["CurrentRankName_Localised"] = x.current_rank_name_localised;
        j["event"] = x.event;
        j["SquadronID"] = x.squadron_id;
        j["SquadronName"] = x.squadron_name;
        j["timestamp"] = x.timestamp;
    }
}


