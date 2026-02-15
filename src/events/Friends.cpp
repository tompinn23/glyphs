#include "Friends.hpp"
#include "factory.hpp"

template event make_event<hue::friends>(const nlohmann::json &j);
