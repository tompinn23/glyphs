#include "FetchRemoteModule.hpp"
#include "factory.hpp"

template event make_event<hue::fetch_remote_module>(const nlohmann::json &j);
