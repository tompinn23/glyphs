#include "SquadronPromotion.hpp"
#include "factory.hpp"

template event make_event<hue::squadron_promotion>(const nlohmann::json &j);
