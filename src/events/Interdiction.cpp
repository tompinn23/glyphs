#include "Interdiction.hpp"
#include "factory.hpp"

template event make_event<hue::interdiction>(const nlohmann::json &j);
