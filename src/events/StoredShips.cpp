#include "StoredShips.hpp"
#include "factory.hpp"

template event make_event<hue::stored_ships>(const nlohmann::json &j);
