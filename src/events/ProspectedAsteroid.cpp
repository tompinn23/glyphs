#include "ProspectedAsteroid.hpp"
#include "factory.hpp"

template event make_event<hue::prospected_asteroid>(const nlohmann::json &j);
