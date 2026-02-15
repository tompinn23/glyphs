#include "SquadronCreated.hpp"
#include "factory.hpp"

template event make_event<hue::squadron_created>(const nlohmann::json &j);
