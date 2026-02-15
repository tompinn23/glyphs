#include "FighterRebuilt.hpp"
#include "factory.hpp"

template event make_event<hue::fighter_rebuilt>(const nlohmann::json &j);
