//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     squadron_demotion data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct squadron_demotion {
        std::string event;
        int64_t new_rank;
        std::optional<std::string> new_rank_name;
        std::optional<std::string> new_rank_name_localised;
        int64_t old_rank;
        std::optional<std::string> old_rank_name;
        std::optional<std::string> old_rank_name_localised;
        std::optional<int64_t> squadron_id;
        std::string squadron_name;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, squadron_demotion & x);
    void to_json(json & j, const squadron_demotion & x);

    inline void from_json(const json & j, squadron_demotion& x) {
        x.event = j.at("event").get<std::string>();
        x.new_rank = j.at("NewRank").get<int64_t>();
        x.new_rank_name = get_stack_optional<std::string>(j, "NewRankName");
        x.new_rank_name_localised = get_stack_optional<std::string>(j, "NewRankName_Localised");
        x.old_rank = j.at("OldRank").get<int64_t>();
        x.old_rank_name = get_stack_optional<std::string>(j, "OldRankName");
        x.old_rank_name_localised = get_stack_optional<std::string>(j, "OldRankName_Localised");
        x.squadron_id = get_stack_optional<int64_t>(j, "SquadronID");
        x.squadron_name = j.at("SquadronName").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const squadron_demotion & x) {
        j = json::object();
        j["event"] = x.event;
        j["NewRank"] = x.new_rank;
        j["NewRankName"] = x.new_rank_name;
        j["NewRankName_Localised"] = x.new_rank_name_localised;
        j["OldRank"] = x.old_rank;
        j["OldRankName"] = x.old_rank_name;
        j["OldRankName_Localised"] = x.old_rank_name_localised;
        j["SquadronID"] = x.squadron_id;
        j["SquadronName"] = x.squadron_name;
        j["timestamp"] = x.timestamp;
    }
}


