#include "SetUserShipName.hpp"
#include "factory.hpp"

template event make_event<hue::set_user_ship_name>(const nlohmann::json &j);
