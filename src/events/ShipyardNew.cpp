#include "ShipyardNew.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard_new>(const nlohmann::json &j);
