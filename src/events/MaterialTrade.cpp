#include "MaterialTrade.hpp"
#include "factory.hpp"

template event make_event<hue::material_trade>(const nlohmann::json &j);
