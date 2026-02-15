#include "RepairDrone.hpp"
#include "factory.hpp"

template event make_event<hue::repair_drone>(const nlohmann::json &j);
