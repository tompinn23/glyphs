#include "SAASignalsFound.hpp"
#include "factory.hpp"

template event make_event<hue::saa_signals_found>(const nlohmann::json &j);
