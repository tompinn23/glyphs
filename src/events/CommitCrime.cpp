#include "CommitCrime.hpp"
#include "factory.hpp"

template event make_event<hue::commit_crime>(const nlohmann::json &j);
