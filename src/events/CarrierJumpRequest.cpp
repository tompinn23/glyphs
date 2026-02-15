#include "CarrierJumpRequest.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_jump_request>(const nlohmann::json &j);
