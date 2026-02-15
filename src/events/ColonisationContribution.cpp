#include "ColonisationContribution.hpp"
#include "factory.hpp"

template event make_event<hue::colonisation_contribution>(const nlohmann::json &j);
