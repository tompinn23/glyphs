#include "RequestPowerMicroResources.hpp"
#include "factory.hpp"

template event make_event<hue::request_power_micro_resources>(const nlohmann::json &j);
