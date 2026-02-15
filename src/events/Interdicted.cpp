#include "Interdicted.hpp"
#include "factory.hpp"

template event make_event<hue::interdicted>(const nlohmann::json &j);
