#include "PayFines.hpp"
#include "factory.hpp"

template event make_event<hue::pay_fines>(const nlohmann::json &j);
