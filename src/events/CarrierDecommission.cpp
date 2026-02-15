#include "CarrierDecommission.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_decommission>(const nlohmann::json &j);
