#include "BuyAmmo.hpp"
#include "factory.hpp"

template event make_event<hue::buy_ammo>(const nlohmann::json &j);
