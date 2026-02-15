#include "ShipyardRedeem.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard_redeem>(const nlohmann::json &j);
