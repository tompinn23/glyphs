#include "CreateSuitLoadout.hpp"
#include "factory.hpp"

template event make_event<hue::create_suit_loadout>(const nlohmann::json &j);
