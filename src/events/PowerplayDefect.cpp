#include "PowerplayDefect.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay_defect>(const nlohmann::json &j);
