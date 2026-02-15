#include "Fileheader.hpp"
#include "factory.hpp"

template event make_event<hue::fileheader>(const nlohmann::json &j);
