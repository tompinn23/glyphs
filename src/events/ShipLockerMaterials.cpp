#include "ShipLockerMaterials.hpp"
#include "factory.hpp"

template event make_event<hue::ship_locker_materials>(const nlohmann::json &j);
