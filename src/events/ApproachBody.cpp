#include "ApproachBody.hpp"
#include "factory.hpp"

template event make_event<hue::approach_body>(const nlohmann::json &j);
