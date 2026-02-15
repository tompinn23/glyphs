#include "DockingTimeout.hpp"
#include "factory.hpp"

template event make_event<hue::docking_timeout>(const nlohmann::json &j);
