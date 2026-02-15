#include "MultiSellExplorationData.hpp"
#include "factory.hpp"

template event make_event<hue::multi_sell_exploration_data>(const nlohmann::json &j);
