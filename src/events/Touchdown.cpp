#include "Touchdown.hpp"
#include "factory.hpp"

template event make_event<hue::touchdown>(const nlohmann::json &j);
