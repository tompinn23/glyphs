#include "PowerplayLeave.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay_leave>(const nlohmann::json &j);
