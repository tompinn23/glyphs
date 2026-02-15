#include "DropItems.hpp"
#include "factory.hpp"

template event make_event<hue::drop_items>(const nlohmann::json &j);
