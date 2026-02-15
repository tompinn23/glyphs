#include "ShipyardBuy.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard_buy>(const nlohmann::json &j);
