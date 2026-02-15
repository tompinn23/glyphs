#include "PowerplayCollect.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay_collect>(const nlohmann::json &j);
