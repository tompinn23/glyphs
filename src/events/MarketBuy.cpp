#include "MarketBuy.hpp"
#include "factory.hpp"

template event make_event<hue::market_buy>(const nlohmann::json &j);
