#include "ModuleBuy.hpp"
#include "factory.hpp"

template event make_event<hue::module_buy>(const nlohmann::json &j);
