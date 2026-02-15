#include "ModuleSell.hpp"
#include "factory.hpp"

template event make_event<hue::module_sell>(const nlohmann::json &j);
