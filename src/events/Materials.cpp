#include "Materials.hpp"
#include "factory.hpp"

template event make_event<hue::materials>(const nlohmann::json &j);
