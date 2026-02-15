#include "ShipTargeted.hpp"
#include "factory.hpp"

template event make_event<hue::ship_targeted>(const nlohmann::json &j);
