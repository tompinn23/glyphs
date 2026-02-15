#include "Backpack.hpp"
#include "factory.hpp"

template event make_event<hue::backpack>(const nlohmann::json &j);
