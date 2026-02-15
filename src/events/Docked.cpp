#include "Docked.hpp"
#include "factory.hpp"

template event make_event<hue::docked>(const nlohmann::json &j);
