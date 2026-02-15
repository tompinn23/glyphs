#include "CancelDropship.hpp"
#include "factory.hpp"

template event make_event<hue::cancel_dropship>(const nlohmann::json &j);
