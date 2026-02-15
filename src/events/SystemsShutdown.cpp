#include "SystemsShutdown.hpp"
#include "factory.hpp"

template event make_event<hue::systems_shutdown>(const nlohmann::json &j);
