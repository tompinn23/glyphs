#include "SellSuit.hpp"
#include "factory.hpp"

template event make_event<hue::sell_suit>(const nlohmann::json &j);
