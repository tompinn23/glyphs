#include "LeaveBody.hpp"
#include "factory.hpp"

template event make_event<hue::leave_body>(const nlohmann::json &j);
