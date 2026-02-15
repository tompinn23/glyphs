#include "Resurrect.hpp"
#include "factory.hpp"

template event make_event<hue::resurrect>(const nlohmann::json &j);
