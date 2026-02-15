#include "MissionRedirected.hpp"
#include "factory.hpp"

template event make_event<hue::mission_redirected>(const nlohmann::json &j);
