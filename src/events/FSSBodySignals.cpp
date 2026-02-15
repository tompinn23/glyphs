#include "FSSBodySignals.hpp"
#include "factory.hpp"

template event make_event<hue::fss_body_signals>(const nlohmann::json &j);
