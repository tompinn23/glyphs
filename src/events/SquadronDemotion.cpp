#include "SquadronDemotion.hpp"
#include "factory.hpp"

template event make_event<hue::squadron_demotion>(const nlohmann::json &j);
