#include "Promotion.hpp"
#include "factory.hpp"

template event make_event<hue::promotion>(const nlohmann::json &j);
