#include "HeatWarning.hpp"
#include "factory.hpp"

template event make_event<hue::heat_warning>(const nlohmann::json &j);
