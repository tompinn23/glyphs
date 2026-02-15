#include "SupercruiseExit.hpp"
#include "factory.hpp"

template event make_event<hue::supercruise_exit>(const nlohmann::json &j);
