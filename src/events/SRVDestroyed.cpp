#include "SRVDestroyed.hpp"
#include "factory.hpp"

template event make_event<hue::srv_destroyed>(const nlohmann::json &j);
