#include "PowerplayVoucher.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay_voucher>(const nlohmann::json &j);
