#include "ReservoirReplenished.hpp"
#include "factory.hpp"

template event make_event<hue::reservoir_replenished>(const nlohmann::json &j);
