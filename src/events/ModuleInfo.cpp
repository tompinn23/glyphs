#include "ModuleInfo.hpp"
#include "factory.hpp"

template event make_event<hue::module_info>(const nlohmann::json &j);
