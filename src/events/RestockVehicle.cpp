#include "RestockVehicle.hpp"
#include "factory.hpp"

template event make_event<hue::restock_vehicle>(const nlohmann::json &j);
