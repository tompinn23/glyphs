#include "Embark.hpp"
#include "factory.hpp"

template event make_event<hue::embark>(const nlohmann::json &j);
