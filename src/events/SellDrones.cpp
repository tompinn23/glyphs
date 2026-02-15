#include "SellDrones.hpp"
#include "factory.hpp"

template event make_event<hue::sell_drones>(const nlohmann::json &j);
