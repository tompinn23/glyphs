#include "StoredModules.hpp"
#include "factory.hpp"

template event make_event<hue::stored_modules>(const nlohmann::json &j);
