#include "Progress.hpp"
#include "factory.hpp"

template event make_event<hue::progress>(const nlohmann::json &j);
