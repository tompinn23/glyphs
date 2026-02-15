#include "PayBounties.hpp"
#include "factory.hpp"

template event make_event<hue::pay_bounties>(const nlohmann::json &j);
