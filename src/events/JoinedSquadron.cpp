#include "JoinedSquadron.hpp"
#include "factory.hpp"

template event make_event<hue::joined_squadron>(const nlohmann::json &j);
