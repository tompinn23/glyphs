#include "ClearSavedGame.hpp"
#include "factory.hpp"

template event make_event<hue::clear_saved_game>(const nlohmann::json &j);
