#include "BackpackChange.hpp"
#include "factory.hpp"

template event make_event<hue::backpack_change>(const nlohmann::json &j);
