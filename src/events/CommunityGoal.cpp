#include "CommunityGoal.hpp"
#include "factory.hpp"

template event make_event<hue::community_goal>(const nlohmann::json &j);
