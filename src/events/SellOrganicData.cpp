#include "SellOrganicData.hpp"
#include "factory.hpp"

template event make_event<hue::sell_organic_data>(const nlohmann::json &j);
