#include "PowerplayMerits.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay_merits>(const nlohmann::json &j);
