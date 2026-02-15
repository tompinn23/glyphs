#include "LeftSquadron.hpp"
#include "factory.hpp"

template event make_event<hue::left_squadron>(const nlohmann::json &j);
