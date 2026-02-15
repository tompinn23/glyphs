#include "FCMaterials.hpp"
#include "factory.hpp"

template event make_event<hue::fc_materials>(const nlohmann::json &j);
