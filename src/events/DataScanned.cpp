#include "DataScanned.hpp"
#include "factory.hpp"

template event make_event<hue::data_scanned>(const nlohmann::json &j);
