#include "KickCrewMember.hpp"
#include "factory.hpp"

template event make_event<hue::kick_crew_member>(const nlohmann::json &j);
