#include "BookTaxi.hpp"
#include "factory.hpp"

template event make_event<hue::book_taxi>(const nlohmann::json &j);
