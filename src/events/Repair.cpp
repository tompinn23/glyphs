#include "Repair.hpp"
#include "factory.hpp"

template event make_event<hue::repair>(const nlohmann::json &j);
