#include "Shipyard.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard>(const nlohmann::json &j);
