#include "CarrierDockingPermission.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_docking_permission>(const nlohmann::json &j);
