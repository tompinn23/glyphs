#include "ReceiveText.hpp"
#include "factory.hpp"

template event make_event<hue::receive_text>(const nlohmann::json &j);
