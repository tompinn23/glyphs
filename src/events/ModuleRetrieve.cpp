#include "ModuleRetrieve.hpp"
#include "factory.hpp"

template event make_event<hue::module_retrieve>(const nlohmann::json &j);
