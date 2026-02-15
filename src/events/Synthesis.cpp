#include "Synthesis.hpp"
#include "factory.hpp"

template event make_event<hue::synthesis>(const nlohmann::json &j);
