#include "DockingGranted.hpp"
#include "factory.hpp"

template event make_event<hue::docking_granted>(const nlohmann::json &j);
