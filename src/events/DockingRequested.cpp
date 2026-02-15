#include "DockingRequested.hpp"
#include "factory.hpp"

template event make_event<hue::docking_requested>(const nlohmann::json &j);
