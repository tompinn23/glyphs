#include "NewCommander.hpp"
#include "factory.hpp"

template event make_event<hue::new_commander>(const nlohmann::json &j);
