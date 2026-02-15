//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     repair_drone data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when the player's ship has been repaired by a repair drone. Each of the
     * values indicate the amount of damage that has been repaired
     */
    struct repair_drone {
        std::optional<double> cockpit_repaired;
        std::optional<double> corrosion_repaired;
        std::string event;
        std::optional<double> hull_repaired;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, repair_drone & x);
    void to_json(json & j, const repair_drone & x);

    inline void from_json(const json & j, repair_drone& x) {
        x.cockpit_repaired = get_stack_optional<double>(j, "CockpitRepaired");
        x.corrosion_repaired = get_stack_optional<double>(j, "CorrosionRepaired");
        x.event = j.at("event").get<std::string>();
        x.hull_repaired = get_stack_optional<double>(j, "HullRepaired");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const repair_drone & x) {
        j = json::object();
        j["CockpitRepaired"] = x.cockpit_repaired;
        j["CorrosionRepaired"] = x.corrosion_repaired;
        j["event"] = x.event;
        j["HullRepaired"] = x.hull_repaired;
        j["timestamp"] = x.timestamp;
    }
}


