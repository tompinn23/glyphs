#include "CarrierModulePack.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_module_pack>(const nlohmann::json &j);
