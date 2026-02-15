#include "Loadout.hpp"
#include "factory.hpp"

template event make_event<hue::loadout>(const nlohmann::json &j);
