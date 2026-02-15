#include "Shutdown.hpp"
#include "factory.hpp"

template event make_event<hue::shutdown>(const nlohmann::json &j);
