#include "CrewMemberRoleChange.hpp"
#include "factory.hpp"

template event make_event<hue::crew_member_role_change>(const nlohmann::json &j);
