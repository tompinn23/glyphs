#include "HullDamage.hpp"
#include "factory.hpp"

template event make_event<hue::hull_damage>(const nlohmann::json &j);
