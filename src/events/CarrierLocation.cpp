#include "CarrierLocation.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_location>(const nlohmann::json &j);
