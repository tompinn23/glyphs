#include "QuitACrew.hpp"
#include "factory.hpp"

template event make_event<hue::quit_a_crew>(const nlohmann::json &j);
