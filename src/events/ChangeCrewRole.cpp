#include "ChangeCrewRole.hpp"
#include "factory.hpp"

template event make_event<hue::change_crew_role>(const nlohmann::json &j);
