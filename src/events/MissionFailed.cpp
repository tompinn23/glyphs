#include "MissionFailed.hpp"
#include "factory.hpp"

template event make_event<hue::mission_failed>(const nlohmann::json &j);
