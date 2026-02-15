#include "StartJump.hpp"
#include "factory.hpp"

template event make_event<hue::start_jump>(const nlohmann::json &j);
