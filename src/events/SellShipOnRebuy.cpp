#include "SellShipOnRebuy.hpp"
#include "factory.hpp"

template event make_event<hue::sell_ship_on_rebuy>(const nlohmann::json &j);
