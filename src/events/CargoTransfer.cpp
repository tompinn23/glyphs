#include "CargoTransfer.hpp"
#include "factory.hpp"

template event make_event<hue::cargo_transfer>(const nlohmann::json &j);
