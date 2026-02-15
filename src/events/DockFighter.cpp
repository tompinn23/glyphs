#include "DockFighter.hpp"
#include "factory.hpp"

template event make_event<hue::dock_fighter>(const nlohmann::json &j);
