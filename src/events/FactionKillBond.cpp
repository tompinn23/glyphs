#include "FactionKillBond.hpp"
#include "factory.hpp"

template event make_event<hue::faction_kill_bond>(const nlohmann::json &j);
