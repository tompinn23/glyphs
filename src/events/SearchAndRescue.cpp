#include "SearchAndRescue.hpp"
#include "factory.hpp"

template event make_event<hue::search_and_rescue>(const nlohmann::json &j);
