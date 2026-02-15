#include "FSDJump.hpp"
#include "factory.hpp"

template event make_event<hue::fsd_jump>(const nlohmann::json &j);
