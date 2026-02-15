#include "NpcCrewRank.hpp"
#include "factory.hpp"

template event make_event<hue::npc_crew_rank>(const nlohmann::json &j);
