#include "MissionCompleted.hpp"
#include "factory.hpp"

template event make_event<hue::mission_completed>(const nlohmann::json &j);
