#include "ShipyardTransfer.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard_transfer>(const nlohmann::json &j);
