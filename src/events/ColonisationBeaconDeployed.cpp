#include "ColonisationBeaconDeployed.hpp"
#include "factory.hpp"

template event make_event<hue::colonisation_beacon_deployed>(const nlohmann::json &j);
