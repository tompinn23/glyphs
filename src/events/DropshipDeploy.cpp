#include "DropshipDeploy.hpp"
#include "factory.hpp"

template event make_event<hue::dropship_deploy>(const nlohmann::json &j);
