#include "CarrierTradeOrder.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_trade_order>(const nlohmann::json &j);
