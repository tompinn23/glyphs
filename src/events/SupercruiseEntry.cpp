#include "SupercruiseEntry.hpp"
#include "factory.hpp"

template event make_event<hue::supercruise_entry>(const nlohmann::json &j);
