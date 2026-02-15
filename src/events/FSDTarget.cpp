#include "FSDTarget.hpp"
#include "factory.hpp"

template event make_event<hue::fsd_target>(const nlohmann::json &j);
