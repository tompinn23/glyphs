#include "CockpitBreached.hpp"
#include "factory.hpp"

template event make_event<hue::cockpit_breached>(const nlohmann::json &j);
