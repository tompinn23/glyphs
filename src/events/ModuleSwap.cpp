#include "ModuleSwap.hpp"
#include "factory.hpp"

template event make_event<hue::module_swap>(const nlohmann::json &j);
