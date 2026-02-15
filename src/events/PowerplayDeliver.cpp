#include "PowerplayDeliver.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay_deliver>(const nlohmann::json &j);
