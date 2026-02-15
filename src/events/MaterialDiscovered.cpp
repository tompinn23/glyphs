#include "MaterialDiscovered.hpp"
#include "factory.hpp"

template event make_event<hue::material_discovered>(const nlohmann::json &j);
