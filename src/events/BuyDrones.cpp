#include "BuyDrones.hpp"
#include "factory.hpp"

template event make_event<hue::buy_drones>(const nlohmann::json &j);
