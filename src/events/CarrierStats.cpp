#include "CarrierStats.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_stats>(const nlohmann::json &j);
