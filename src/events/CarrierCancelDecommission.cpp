#include "CarrierCancelDecommission.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_cancel_decommission>(const nlohmann::json &j);
