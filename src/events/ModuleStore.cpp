#include "ModuleStore.hpp"
#include "factory.hpp"

template event make_event<hue::module_store>(const nlohmann::json &j);
