#include "CrewAssign.hpp"
#include "factory.hpp"

template event make_event<hue::crew_assign>(const nlohmann::json &j);
