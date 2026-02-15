#include "BuyExplorationData.hpp"
#include "factory.hpp"

template event make_event<hue::buy_exploration_data>(const nlohmann::json &j);
