#include "MaterialCollected.hpp"
#include "factory.hpp"

template event make_event<hue::material_collected>(const nlohmann::json &j);
