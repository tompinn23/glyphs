#include "RefuelAll.hpp"
#include "factory.hpp"

template event make_event<hue::refuel_all>(const nlohmann::json &j);
