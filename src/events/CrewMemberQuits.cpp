#include "CrewMemberQuits.hpp"
#include "factory.hpp"

template event make_event<hue::crew_member_quits>(const nlohmann::json &j);
