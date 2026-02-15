#include "PowerplayVote.hpp"
#include "factory.hpp"

template event make_event<hue::powerplay_vote>(const nlohmann::json &j);
