#include "SuitLoadout.hpp"
#include "factory.hpp"

template event make_event<hue::suit_loadout>(const nlohmann::json &j);
