#include "CollectCargo.hpp"
#include "factory.hpp"

template event make_event<hue::collect_cargo>(const nlohmann::json &j);
