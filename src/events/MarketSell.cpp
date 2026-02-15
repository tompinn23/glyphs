#include "MarketSell.hpp"
#include "factory.hpp"

template event make_event<hue::market_sell>(const nlohmann::json &j);
