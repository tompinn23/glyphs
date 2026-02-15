#include "DatalinkVoucher.hpp"
#include "factory.hpp"

template event make_event<hue::datalink_voucher>(const nlohmann::json &j);
