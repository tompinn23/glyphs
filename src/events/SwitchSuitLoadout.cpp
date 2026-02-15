#include "SwitchSuitLoadout.hpp"
#include "factory.hpp"

template event make_event<hue::switch_suit_loadout>(const nlohmann::json &j);
