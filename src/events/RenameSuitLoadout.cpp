#include "RenameSuitLoadout.hpp"
#include "factory.hpp"

template event make_event<hue::rename_suit_loadout>(const nlohmann::json &j);
