#include "Scan.hpp"
#include "factory.hpp"

template event make_event<hue::scan>(const nlohmann::json &j);
