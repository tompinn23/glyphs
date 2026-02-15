#include "Commander.hpp"
#include "factory.hpp"

template event make_event<hue::commander>(const nlohmann::json &j);
