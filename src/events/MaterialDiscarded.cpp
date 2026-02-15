#include "MaterialDiscarded.hpp"
#include "factory.hpp"

template event make_event<hue::material_discarded>(const nlohmann::json &j);
