#include "JetConeBoost.hpp"
#include "factory.hpp"

template event make_event<hue::jet_cone_boost>(const nlohmann::json &j);
