#include "ShipRedeemed.hpp"
#include "factory.hpp"

template event make_event<hue::ship_redeemed>(const nlohmann::json &j);
