#include "LoadoutRemoveModule.hpp"
#include "factory.hpp"

template event make_event<hue::loadout_remove_module>(const nlohmann::json &j);
