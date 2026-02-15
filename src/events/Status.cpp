#include "Status.hpp"
#include "factory.hpp"

template event make_event<hue::status>(const nlohmann::json &j);
