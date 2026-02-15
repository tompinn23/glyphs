#include "ShipyardSell.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard_sell>(const nlohmann::json &j);
