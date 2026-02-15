#include "LaunchSRV.hpp"
#include "factory.hpp"

template event make_event<hue::launch_srv>(const nlohmann::json &j);
