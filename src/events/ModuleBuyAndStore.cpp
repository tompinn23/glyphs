#include "ModuleBuyAndStore.hpp"
#include "factory.hpp"

template event make_event<hue::module_buy_and_store>(const nlohmann::json &j);
