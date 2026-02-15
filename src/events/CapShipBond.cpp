#include "CapShipBond.hpp"
#include "factory.hpp"

template event make_event<hue::cap_ship_bond>(const nlohmann::json &j);
