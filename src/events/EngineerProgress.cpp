#include "EngineerProgress.hpp"
#include "factory.hpp"

template event make_event<hue::engineer_progress>(const nlohmann::json &j);
