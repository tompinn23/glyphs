#include "SquadronApplicationRejected.hpp"
#include "factory.hpp"

template event make_event<hue::squadron_application_rejected>(const nlohmann::json &j);
