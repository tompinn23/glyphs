#include "UpgradeSuit.hpp"
#include "factory.hpp"

template event make_event<hue::upgrade_suit>(const nlohmann::json &j);
