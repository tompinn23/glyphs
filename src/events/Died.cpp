#include "Died.hpp"
#include "factory.hpp"

template event make_event<hue::died>(const nlohmann::json &j);
