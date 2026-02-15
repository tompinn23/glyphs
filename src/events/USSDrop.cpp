#include "USSDrop.hpp"
#include "factory.hpp"

template event make_event<hue::uss_drop>(const nlohmann::json &j);
