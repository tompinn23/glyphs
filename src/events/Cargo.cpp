#include "Cargo.hpp"
#include "factory.hpp"

template event make_event<hue::cargo>(const nlohmann::json &j);
