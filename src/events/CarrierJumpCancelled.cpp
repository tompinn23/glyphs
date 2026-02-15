#include "CarrierJumpCancelled.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_jump_cancelled>(const nlohmann::json &j);
