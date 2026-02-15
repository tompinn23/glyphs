#include "Bounty.hpp"
#include "factory.hpp"

template event make_event<hue::bounty>(const nlohmann::json &j);
