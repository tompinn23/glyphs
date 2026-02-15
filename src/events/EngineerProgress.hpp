//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     engineer_progress data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct engineer {
        std::string engineer;
        int64_t engineer_id;
        std::string progress;
        std::optional<int64_t> rank;
        std::optional<int64_t> rank_progress;
    };

    /**
     * When Written: when a player increases their access to an engineer
     */
    struct engineer_progress {
        /**
         * Update for one engineer
         */
        std::optional<std::string> engineer;
        /**
         * Update for one engineer
         */
        std::optional<int64_t> engineer_id;
        /**
         * Summary at startup
         */
        std::optional<std::vector<hue::engineer>> engineers;
        std::string event;
        /**
         * Update for one engineer
         */
        std::optional<std::string> progress;
        /**
         * Update for one engineer
         */
        std::optional<int64_t> rank;
        /**
         * Uncertain whether this is actually logged
         */
        std::optional<int64_t> rank_progress;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, engineer & x);
    void to_json(json & j, const engineer & x);

    void from_json(const json & j, engineer_progress & x);
    void to_json(json & j, const engineer_progress & x);

    inline void from_json(const json & j, engineer& x) {
        x.engineer = j.at("Engineer").get<std::string>();
        x.engineer_id = j.at("EngineerID").get<int64_t>();
        x.progress = j.at("Progress").get<std::string>();
        x.rank = get_stack_optional<int64_t>(j, "Rank");
        x.rank_progress = get_stack_optional<int64_t>(j, "RankProgress");
    }

    inline void to_json(json & j, const engineer & x) {
        j = json::object();
        j["Engineer"] = x.engineer;
        j["EngineerID"] = x.engineer_id;
        j["Progress"] = x.progress;
        j["Rank"] = x.rank;
        j["RankProgress"] = x.rank_progress;
    }

    inline void from_json(const json & j, engineer_progress& x) {
        x.engineer = get_stack_optional<std::string>(j, "Engineer");
        x.engineer_id = get_stack_optional<int64_t>(j, "EngineerID");
        x.engineers = get_stack_optional<std::vector<engineer>>(j, "Engineers");
        x.event = j.at("event").get<std::string>();
        x.progress = get_stack_optional<std::string>(j, "Progress");
        x.rank = get_stack_optional<int64_t>(j, "Rank");
        x.rank_progress = get_stack_optional<int64_t>(j, "RankProgress");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const engineer_progress & x) {
        j = json::object();
        j["Engineer"] = x.engineer;
        j["EngineerID"] = x.engineer_id;
        j["Engineers"] = x.engineers;
        j["event"] = x.event;
        j["Progress"] = x.progress;
        j["Rank"] = x.rank;
        j["RankProgress"] = x.rank_progress;
        j["timestamp"] = x.timestamp;
    }
}


