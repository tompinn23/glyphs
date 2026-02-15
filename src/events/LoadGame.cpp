#include "LoadGame.hpp"
#include "factory.hpp"

template event make_event<hue::load_game>(const nlohmann::json &j);
