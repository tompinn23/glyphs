#include "FighterDestroyed.hpp"
#include "factory.hpp"

template event make_event<hue::fighter_destroyed>(const nlohmann::json &j);
