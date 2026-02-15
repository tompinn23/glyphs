#include "NavBeaconScan.hpp"
#include "factory.hpp"

template event make_event<hue::nav_beacon_scan>(const nlohmann::json &j);
