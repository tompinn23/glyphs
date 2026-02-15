#include "Screenshot.hpp"
#include "factory.hpp"

template event make_event<hue::screenshot>(const nlohmann::json &j);
