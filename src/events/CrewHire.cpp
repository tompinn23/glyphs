#include "CrewHire.hpp"
#include "factory.hpp"

template event make_event<hue::crew_hire>(const nlohmann::json &j);
