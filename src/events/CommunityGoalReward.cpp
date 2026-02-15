#include "CommunityGoalReward.hpp"
#include "factory.hpp"

template event make_event<hue::community_goal_reward>(const nlohmann::json &j);
