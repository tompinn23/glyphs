#include "LaunchFighter.hpp"
#include "factory.hpp"

template event make_event<hue::launch_fighter>(const nlohmann::json &j);
