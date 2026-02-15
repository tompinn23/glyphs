#include "MassModuleStore.hpp"
#include "factory.hpp"

template event make_event<hue::mass_module_store>(const nlohmann::json &j);
