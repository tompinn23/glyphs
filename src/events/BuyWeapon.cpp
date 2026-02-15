#include "BuyWeapon.hpp"
#include "factory.hpp"

template event make_event<hue::buy_weapon>(const nlohmann::json &j);
