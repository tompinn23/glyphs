#include "CodexEntry.hpp"
#include "factory.hpp"

template event make_event<hue::codex_entry>(const nlohmann::json &j);
