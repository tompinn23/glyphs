#include "Outfitting.hpp"
#include "factory.hpp"

template event make_event<hue::outfitting>(const nlohmann::json &j);
