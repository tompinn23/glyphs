#include "CrewMemberJoins.hpp"
#include "factory.hpp"

template event make_event<hue::crew_member_joins>(const nlohmann::json &j);
