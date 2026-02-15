#include "CrewFire.hpp"
#include "factory.hpp"

template event make_event<hue::crew_fire>(const nlohmann::json &j);
