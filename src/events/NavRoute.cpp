#include "NavRoute.hpp"
#include "factory.hpp"

template event make_event<hue::nav_route>(const nlohmann::json &j);
