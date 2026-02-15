#include "CarrierCrewServices.hpp"
#include "factory.hpp"

template event make_event<hue::carrier_crew_services>(const nlohmann::json &j);
