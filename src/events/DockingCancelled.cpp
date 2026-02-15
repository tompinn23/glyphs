#include "DockingCancelled.hpp"
#include "factory.hpp"

template event make_event<hue::docking_cancelled>(const nlohmann::json &j);
