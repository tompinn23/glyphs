#include "SellWeapon.hpp"
#include "factory.hpp"

template event make_event<hue::sell_weapon>(const nlohmann::json &j);
