#include "EjectCargo.hpp"
#include "factory.hpp"

template event make_event<hue::eject_cargo>(const nlohmann::json &j);
