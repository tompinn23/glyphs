#include "SendText.hpp"
#include "factory.hpp"

template event make_event<hue::send_text>(const nlohmann::json &j);
