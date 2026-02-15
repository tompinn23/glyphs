#include "RedeemVoucher.hpp"
#include "factory.hpp"

template event make_event<hue::redeem_voucher>(const nlohmann::json &j);
