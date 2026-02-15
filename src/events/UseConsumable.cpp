#include "UseConsumable.hpp"
#include "factory.hpp"

template event make_event<hue::use_consumable>(const nlohmann::json &j);
