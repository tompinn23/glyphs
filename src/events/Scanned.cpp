#include "Scanned.hpp"
#include "factory.hpp"

template event make_event<hue::scanned>(const nlohmann::json &j);
