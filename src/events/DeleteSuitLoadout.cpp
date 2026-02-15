#include "DeleteSuitLoadout.hpp"
#include "factory.hpp"

template event make_event<hue::delete_suit_loadout>(const nlohmann::json &j);
