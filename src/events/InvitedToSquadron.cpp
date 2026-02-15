#include "InvitedToSquadron.hpp"
#include "factory.hpp"

template event make_event<hue::invited_to_squadron>(const nlohmann::json &j);
