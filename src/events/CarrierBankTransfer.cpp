#include "CarrierBankTransfer.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_bank_transfer>(const nlohmann::json &j);
