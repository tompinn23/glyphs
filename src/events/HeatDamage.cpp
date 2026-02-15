#include "HeatDamage.hpp"
#include "factory.hpp"

template event make_event<hue::heat_damage>(const nlohmann::json &j);
