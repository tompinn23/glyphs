#include "Powerplay.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay>(const nlohmann::json &j);
