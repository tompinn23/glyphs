#include "CommunityGoalDiscard.hpp"
#include "factory.hpp"

template event make_event<hue::community_goal_discard>(const nlohmann::json &j);
