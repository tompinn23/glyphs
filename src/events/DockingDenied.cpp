#include "DockingDenied.hpp"
#include "factory.hpp"

template event make_event<hue::docking_denied>(const nlohmann::json &j);
