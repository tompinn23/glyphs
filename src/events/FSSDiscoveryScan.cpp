#include "FSSDiscoveryScan.hpp"
#include "factory.hpp"

template event make_event<hue::fss_discovery_scan>(const nlohmann::json &j);
