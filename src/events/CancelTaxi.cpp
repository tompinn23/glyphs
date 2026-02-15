#include "CancelTaxi.hpp"
#include "factory.hpp"

template event make_event<hue::cancel_taxi>(const nlohmann::json &j);
