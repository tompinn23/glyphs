#include "FSSAllBodiesFound.hpp"
#include "factory.hpp"

template event make_event<hue::fss_all_bodies_found>(const nlohmann::json &j);
