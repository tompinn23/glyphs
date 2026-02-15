#include "LoadoutEquipModule.hpp"
#include "factory.hpp"

template event make_event<hue::loadout_equip_module>(const nlohmann::json &j);
