#include "Resupply.hpp"
#include "factory.hpp"

template event make_event<hue::resupply>(const nlohmann::json &j);
