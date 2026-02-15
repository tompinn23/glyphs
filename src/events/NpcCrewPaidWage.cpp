#include "NpcCrewPaidWage.hpp"
#include "factory.hpp"

template event make_event<hue::npc_crew_paid_wage>(const nlohmann::json &j);
