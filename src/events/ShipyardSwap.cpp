#include "ShipyardSwap.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard_swap>(const nlohmann::json &j);
