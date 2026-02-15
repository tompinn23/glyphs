#include "CarrierDepositFuel.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_deposit_fuel>(const nlohmann::json &j);
