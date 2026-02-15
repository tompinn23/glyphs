#include "ShieldState.hpp"
#include "factory.hpp"

template event make_event<hue::shield_state>(const nlohmann::json &j);
