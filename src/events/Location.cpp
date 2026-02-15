#include "Location.hpp"
#include "factory.hpp"

template event make_event<hue::location>(const nlohmann::json &j);
