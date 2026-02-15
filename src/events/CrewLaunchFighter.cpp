#include "CrewLaunchFighter.hpp"
#include "factory.hpp"

template event make_event<hue::crew_launch_fighter>(const nlohmann::json &j);
