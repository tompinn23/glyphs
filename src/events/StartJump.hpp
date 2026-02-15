//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     start_jump data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: at the start of a Hyperspace or Supercruise jump (start of countdown)
     */
    struct start_jump {
        std::string event;
        std::string jump_type;
        /**
         * only for a hyperspace jump
         */
        std::optional<std::string> star_class;
        std::optional<std::string> star_system;
        std::optional<int64_t> system_address;
        std::optional<bool> taxi;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, start_jump & x);
    void to_json(json & j, const start_jump & x);

    inline void from_json(const json & j, start_jump& x) {
        x.event = j.at("event").get<std::string>();
        x.jump_type = j.at("JumpType").get<std::string>();
        x.star_class = get_stack_optional<std::string>(j, "StarClass");
        x.star_system = get_stack_optional<std::string>(j, "StarSystem");
        x.system_address = get_stack_optional<int64_t>(j, "SystemAddress");
        x.taxi = get_stack_optional<bool>(j, "Taxi");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const start_jump & x) {
        j = json::object();
        j["event"] = x.event;
        j["JumpType"] = x.jump_type;
        j["StarClass"] = x.star_class;
        j["StarSystem"] = x.star_system;
        j["SystemAddress"] = x.system_address;
        j["Taxi"] = x.taxi;
        j["timestamp"] = x.timestamp;
    }
}


