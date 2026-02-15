#include "Music.hpp"
#include "factory.hpp"

template event make_event<hue::music>(const nlohmann::json &j);
