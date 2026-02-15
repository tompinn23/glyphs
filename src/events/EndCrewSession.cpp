#include "EndCrewSession.hpp"
#include "factory.hpp"

template event make_event<hue::end_crew_session>(const nlohmann::json &j);
