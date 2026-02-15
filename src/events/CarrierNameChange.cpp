#include "CarrierNameChange.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_name_change>(const nlohmann::json &j);
