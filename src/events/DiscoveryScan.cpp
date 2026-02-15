#include "DiscoveryScan.hpp"
#include "factory.hpp"

template event make_event<hue::discovery_scan>(const nlohmann::json &j);
