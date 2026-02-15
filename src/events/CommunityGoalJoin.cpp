#include "CommunityGoalJoin.hpp"
#include "factory.hpp"

template event make_event<hue::community_goal_join>(const nlohmann::json &j);
