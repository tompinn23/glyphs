#include "BookDropship.hpp"
#include "factory.hpp"

template event make_event<hue::book_dropship>(const nlohmann::json &j);
