#include "SquadronApplicationApproved.hpp"
#include "factory.hpp"

template event make_event<hue::squadron_application_approved>(const nlohmann::json &j);
