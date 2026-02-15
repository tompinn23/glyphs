#include "BuySuit.hpp"
#include "factory.hpp"

template event make_event<hue::buy_suit>(const nlohmann::json &j);
