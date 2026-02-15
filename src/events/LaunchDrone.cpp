#include "LaunchDrone.hpp"
#include "factory.hpp"

template event make_event<hue::launch_drone>(const nlohmann::json &j);
