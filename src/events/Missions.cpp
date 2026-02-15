#include "Missions.hpp"
#include "factory.hpp"

template event make_event<hue::missions>(const nlohmann::json &j);
