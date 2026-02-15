#include "CarrierShipPack.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_ship_pack>(const nlohmann::json &j);
