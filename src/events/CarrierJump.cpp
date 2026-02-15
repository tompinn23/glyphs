#include "CarrierJump.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_jump>(const nlohmann::json &j);
