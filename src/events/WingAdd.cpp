#include "WingAdd.hpp"
#include "factory.hpp"

template event make_event<hue::wing_add>(const nlohmann::json &j);
