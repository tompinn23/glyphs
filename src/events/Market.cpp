#include "Market.hpp"
#include "factory.hpp"

template event make_event<hue::market>(const nlohmann::json &j);
