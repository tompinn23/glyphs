#include "UpgradeWeapon.hpp"
#include "factory.hpp"

template event make_event<hue::upgrade_weapon>(const nlohmann::json &j);
