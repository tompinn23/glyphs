#include "Liftoff.hpp"
#include "factory.hpp"

template event make_event<hue::liftoff>(const nlohmann::json &j);
