#include "TradeMicroResources.hpp"
#include "factory.hpp"

template event make_event<hue::trade_micro_resources>(const nlohmann::json &j);
