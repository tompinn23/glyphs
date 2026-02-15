#include "RepairAll.hpp"
#include "factory.hpp"

template event make_event<hue::repair_all>(const nlohmann::json &j);
