#include "RebootRepair.hpp"
#include "factory.hpp"

template event make_event<hue::reboot_repair>(const nlohmann::json &j);
