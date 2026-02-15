#include "Statistics.hpp"
#include "factory.hpp"

template event make_event<hue::statistics>(const nlohmann::json &j);
