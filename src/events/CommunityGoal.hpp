//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     community_goal data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;


    namespace types {
        struct top_tier {
            std::string bonus;
            std::string name;
        };
    }

    struct current_goal {
        /**
         * If the community goal has reached the first success
         */
        std::optional<int64_t> bonus;
        /**
         * A unique ID number for the CG
         */
        int64_t cgid;
        int64_t current_total;
        std::string expiry;
        bool is_complete;
        std::string market_name;
        int64_t num_contributors;
        int64_t player_contribution;
        /**
         * If the community goal is constructed with a fixed-size top rank (ie max reward for top 10
         * players)
         */
        std::optional<bool> player_in_top_rank;
        int64_t player_percentile_band;
        std::string system_name;
        /**
         * If the community goal has reached the first success
         */
        std::optional<std::string> tier_reached;
        /**
         * A description for the CG
         */
        std::string title;
        /**
         * If the community goal is constructed with a fixed-size top rank (ie max reward for top 10
         * players)
         */
        std::optional<int64_t> top_rank_size;
        types::top_tier top_tier;
    };

    /**
     * When written: when the game retrieves info on community goals from the server, and the
     * data has changed since last time. This event contains the current status of all community
     * goals the player is currently subscribed to.
     */
    struct community_goal {
        std::vector<current_goal> current_goals;
        std::string event;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {

    namespace types {

    inline void from_json(const json & j, top_tier& x) {
        x.bonus = j.at("Bonus").get<std::string>();
        x.name = j.at("Name").get<std::string>();
    }

    inline void to_json(json & j, const top_tier & x) {
        j = json::object();
        j["Bonus"] = x.bonus;
        j["Name"] = x.name;
    }
}

    inline void from_json(const json & j, current_goal& x) {
        x.bonus = get_stack_optional<int64_t>(j, "Bonus");
        x.cgid = j.at("CGID").get<int64_t>();
        x.current_total = j.at("CurrentTotal").get<int64_t>();
        x.expiry = j.at("Expiry").get<std::string>();
        x.is_complete = j.at("IsComplete").get<bool>();
        x.market_name = j.at("MarketName").get<std::string>();
        x.num_contributors = j.at("NumContributors").get<int64_t>();
        x.player_contribution = j.at("PlayerContribution").get<int64_t>();
        x.player_in_top_rank = get_stack_optional<bool>(j, "PlayerInTopRank");
        x.player_percentile_band = j.at("PlayerPercentileBand").get<int64_t>();
        x.system_name = j.at("SystemName").get<std::string>();
        x.tier_reached = get_stack_optional<std::string>(j, "TierReached");
        x.title = j.at("Title").get<std::string>();
        x.top_rank_size = get_stack_optional<int64_t>(j, "TopRankSize");
        x.top_tier = j.at("TopTier").get<types::top_tier>();
    }

    inline void to_json(json & j, const current_goal & x) {
        j = json::object();
        j["Bonus"] = x.bonus;
        j["CGID"] = x.cgid;
        j["CurrentTotal"] = x.current_total;
        j["Expiry"] = x.expiry;
        j["IsComplete"] = x.is_complete;
        j["MarketName"] = x.market_name;
        j["NumContributors"] = x.num_contributors;
        j["PlayerContribution"] = x.player_contribution;
        j["PlayerInTopRank"] = x.player_in_top_rank;
        j["PlayerPercentileBand"] = x.player_percentile_band;
        j["SystemName"] = x.system_name;
        j["TierReached"] = x.tier_reached;
        j["Title"] = x.title;
        j["TopRankSize"] = x.top_rank_size;
        j["TopTier"] = x.top_tier;
    }

    inline void from_json(const json & j, community_goal& x) {
        x.current_goals = j.at("CurrentGoals").get<std::vector<current_goal>>();
        x.event = j.at("event").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const community_goal & x) {
        j = json::object();
        j["CurrentGoals"] = x.current_goals;
        j["event"] = x.event;
        j["timestamp"] = x.timestamp;
    }
}


