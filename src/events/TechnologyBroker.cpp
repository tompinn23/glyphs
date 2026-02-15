#include "TechnologyBroker.hpp"
#include "factory.hpp"

template event make_event<hue::technology_broker>(const nlohmann::json &j);
