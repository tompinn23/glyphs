#include "CancelledSquadronApplication.hpp"
#include "factory.hpp"

template event make_event<hue::cancelled_squadron_application>(const nlohmann::json &j);
