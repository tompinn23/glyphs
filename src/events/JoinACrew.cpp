#include "JoinACrew.hpp"
#include "factory.hpp"

template event make_event<hue::join_a_crew>(const nlohmann::json &j);
