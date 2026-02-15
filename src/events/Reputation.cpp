#include "Reputation.hpp"
#include "factory.hpp"

template event make_event<hue::reputation>(const nlohmann::json &j);
