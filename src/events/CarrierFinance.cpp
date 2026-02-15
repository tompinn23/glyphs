#include "CarrierFinance.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_finance>(const nlohmann::json &j);
