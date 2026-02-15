#include "ShipLocker.hpp"
#include "factory.hpp"

template event make_event<hue::ship_locker>(const nlohmann::json &j);
