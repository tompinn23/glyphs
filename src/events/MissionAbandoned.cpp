#include "MissionAbandoned.hpp"
#include "factory.hpp"

template event make_event<hue::mission_abandoned>(const nlohmann::json &j);
