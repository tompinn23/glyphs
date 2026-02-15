#include "MissionAccepted.hpp"
#include "factory.hpp"

template event make_event<hue::mission_accepted>(const nlohmann::json &j);
