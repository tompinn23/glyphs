#include "SharedBookmarkToSquadron.hpp"
#include "factory.hpp"

template event make_event<hue::shared_bookmark_to_squadron>(const nlohmann::json &j);
