#include "CarrierBuy.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_buy>(const nlohmann::json &j);
