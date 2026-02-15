#include "CollectItems.hpp"
#include "factory.hpp"

template event make_event<hue::collect_items>(const nlohmann::json &j);
