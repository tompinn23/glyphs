#include "FSSSignalDiscovered.hpp"
#include "factory.hpp"

template event make_event<hue::fss_signal_discovered>(const nlohmann::json &j);
