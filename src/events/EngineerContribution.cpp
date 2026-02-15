#include "EngineerContribution.hpp"
#include "factory.hpp"

template event make_event<hue::engineer_contribution>(const nlohmann::json &j);
