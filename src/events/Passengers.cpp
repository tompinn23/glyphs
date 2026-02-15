#include "Passengers.hpp"
#include "factory.hpp"

template event make_event<hue::passengers>(const nlohmann::json &j);
