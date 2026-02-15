#include "DisbandedSquadron.hpp"
#include "factory.hpp"

template event make_event<hue::disbanded_squadron>(const nlohmann::json &j);
