#include "WingInvite.hpp"
#include "factory.hpp"

template event make_event<hue::wing_invite>(const nlohmann::json &j);
