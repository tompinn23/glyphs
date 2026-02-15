//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     jet_cone_damage data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when passing through the jet code from a white dwarf or neutron star has
     * caused damage to a ship module
     */
    struct jet_cone_damage {
        std::string event;
        std::string jet_cone_damage_module;
        std::optional<std::string> module_localised;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, jet_cone_damage & x);
    void to_json(json & j, const jet_cone_damage & x);

    inline void from_json(const json & j, jet_cone_damage& x) {
        x.event = j.at("event").get<std::string>();
        x.jet_cone_damage_module = j.at("Module").get<std::string>();
        x.module_localised = get_stack_optional<std::string>(j, "Module_Localised");
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const jet_cone_damage & x) {
        j = json::object();
        j["event"] = x.event;
        j["Module"] = x.jet_cone_damage_module;
        j["Module_Localised"] = x.module_localised;
        j["timestamp"] = x.timestamp;
    }
}


