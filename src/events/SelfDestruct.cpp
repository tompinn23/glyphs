#include "SelfDestruct.hpp"
#include "factory.hpp"

template event make_event<hue::self_destruct>(const nlohmann::json &j);
