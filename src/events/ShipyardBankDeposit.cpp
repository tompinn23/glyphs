#include "ShipyardBankDeposit.hpp"
#include "factory.hpp"

template event make_event<hue::shipyard_bank_deposit>(const nlohmann::json &j);
