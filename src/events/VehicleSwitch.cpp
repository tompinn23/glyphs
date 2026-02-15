#include "VehicleSwitch.hpp"
#include "factory.hpp"

template event make_event<hue::vehicle_switch>(const nlohmann::json &j);
