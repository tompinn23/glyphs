#include "SAAScanComplete.hpp"
#include "factory.hpp"

template event make_event<hue::saa_scan_complete>(const nlohmann::json &j);
