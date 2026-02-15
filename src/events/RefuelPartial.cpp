#include "RefuelPartial.hpp"
#include "factory.hpp"

template event make_event<hue::refuel_partial>(const nlohmann::json &j);
