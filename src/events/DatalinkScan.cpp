#include "DatalinkScan.hpp"
#include "factory.hpp"

template event make_event<hue::datalink_scan>(const nlohmann::json &j);
