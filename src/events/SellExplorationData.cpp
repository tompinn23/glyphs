#include "SellExplorationData.hpp"
#include "factory.hpp"

template event make_event<hue::sell_exploration_data>(const nlohmann::json &j);
