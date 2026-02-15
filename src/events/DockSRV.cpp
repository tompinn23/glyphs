#include "DockSRV.hpp"
#include "factory.hpp"

template event make_event<hue::dock_srv>(const nlohmann::json &j);
