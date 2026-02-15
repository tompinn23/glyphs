#include "PVPKill.hpp"
#include "factory.hpp"

template event make_event<hue::pvp_kill>(const nlohmann::json &j);
