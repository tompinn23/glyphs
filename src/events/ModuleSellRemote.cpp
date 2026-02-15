#include "ModuleSellRemote.hpp"
#include "factory.hpp"

template event make_event<hue::module_sell_remote>(const nlohmann::json &j);
