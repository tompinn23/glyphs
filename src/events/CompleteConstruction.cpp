#include "CompleteConstruction.hpp"
#include "factory.hpp"

template event make_event<hue::complete_construction>(const nlohmann::json &j);
