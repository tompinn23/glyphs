#include "CrimeVictim.hpp"
#include "factory.hpp"

template event make_event<hue::crime_victim>(const nlohmann::json &j);
