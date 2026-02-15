#include "SellMicroResources.hpp"
#include "factory.hpp"

template event make_event<hue::sell_micro_resources>(const nlohmann::json &j);
