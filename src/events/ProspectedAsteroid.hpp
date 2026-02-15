//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     prospected_asteroid data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    struct prospected_material {
        std::string name;
        std::optional<std::string> name_localised;
        double proportion;
    };

    /**
     * When using a prospecting drone
     */
    struct prospected_asteroid {
        std::string content;
        std::optional<std::string> content_localised;
        std::string event;
        std::vector<prospected_material> materials;
        /**
         * If itΓÇÖs a motherlode
         */
        std::optional<std::string> motherlode_material;
        /**
         * If itΓÇÖs a motherlode. The localised value will be omitted if it is exactly the same as
         * MotherlodeMaterial
         */
        std::optional<std::string> motherlode_material_localised;
        /**
         * Percentage of materials remaining
         */
        double remaining;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, prospected_material & x);
    void to_json(json & j, const prospected_material & x);

    void from_json(const json & j, prospected_asteroid & x);
    void to_json(json & j, const prospected_asteroid & x);

    inline void from_json(const json & j, prospected_material& x) {
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.proportion = j.at("Proportion").get<double>();
    }

    inline void to_json(json & j, const prospected_material & x) {
        j = json::object();
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["Proportion"] = x.proportion;
    }

    inline void from_json(const json & j, prospected_asteroid& x) {
        x.content = j.at("Content").get<std::string>();
        x.content_localised = get_stack_optional<std::string>(j, "Content_Localised");
        x.event = j.at("event").get<std::string>();
        x.materials = j.at("Materials").get<std::vector<prospected_material>>();
        x.motherlode_material = get_stack_optional<std::string>(j, "MotherlodeMaterial");
        x.motherlode_material_localised = get_stack_optional<std::string>(j, "MotherlodeMaterial_Localised");
        x.remaining = j.at("Remaining").get<double>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const prospected_asteroid & x) {
        j = json::object();
        j["Content"] = x.content;
        j["Content_Localised"] = x.content_localised;
        j["event"] = x.event;
        j["Materials"] = x.materials;
        j["MotherlodeMaterial"] = x.motherlode_material;
        j["MotherlodeMaterial_Localised"] = x.motherlode_material_localised;
        j["Remaining"] = x.remaining;
        j["timestamp"] = x.timestamp;
    }
}


