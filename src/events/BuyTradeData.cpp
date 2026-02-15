#include "BuyTradeData.hpp"
#include "factory.hpp"

template event make_event<hue::buy_trade_data>(const nlohmann::json &j);
