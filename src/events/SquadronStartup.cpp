#include "SquadronStartup.hpp"
#include "factory.hpp"

template event make_event<hue::squadron_startup>(const nlohmann::json &j);
