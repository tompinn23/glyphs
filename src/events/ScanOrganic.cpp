#include "ScanOrganic.hpp"
#include "factory.hpp"

template event make_event<hue::scan_organic>(const nlohmann::json &j);
