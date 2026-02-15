#include "KickedFromSquadron.hpp"
#include "factory.hpp"

template event make_event<hue::kicked_from_squadron>(const nlohmann::json &j);
