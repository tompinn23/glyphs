//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     engineer_craft data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;

    struct ingredient {
        int64_t count;
        std::string name;
        /**
         * The localised value will be omitted if it is exactly the same as Name
         */
        std::optional<std::string> name_localised;
    };

    /**
     * When Written: when requesting an engineer upgrade
     */
    struct engineer_craft {
        /**
         * when applying a new effect
         */
        std::optional<std::string> apply_experimental_effect;
        int64_t blueprint_id;
        std::string blueprint_name;
        std::optional<std::string> engineer;
        int64_t engineer_id;
        std::string event;
        std::optional<std::string> experimental_effect;
        std::optional<std::string> experimental_effect_localised;
        std::vector<ingredient> ingredients;
        int64_t level;
        std::vector<common::types::modifier> modifiers;
        std::string engineer_craft_module;
        double quality;
        std::string slot;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, ingredient & x);
    void to_json(json & j, const ingredient & x);


    void from_json(const json & j, engineer_craft & x);
    void to_json(json & j, const engineer_craft & x);

    inline void from_json(const json & j, ingredient& x) {
        x.count = j.at("Count").get<int64_t>();
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
    }

    inline void to_json(json & j, const ingredient & x) {
        j = json::object();
        j["Count"] = x.count;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
    }

    inline void from_json(const json & j, engineer_craft& x) {
        x.apply_experimental_effect = get_stack_optional<std::string>(j, "ApplyExperimentalEffect");
        x.blueprint_id = j.at("BlueprintID").get<int64_t>();
        x.blueprint_name = j.at("BlueprintName").get<std::string>();
        x.engineer = get_stack_optional<std::string>(j, "Engineer");
        x.engineer_id = j.at("EngineerID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.experimental_effect = get_stack_optional<std::string>(j, "ExperimentalEffect");
        x.experimental_effect_localised = get_stack_optional<std::string>(j, "ExperimentalEffect_Localised");
        x.ingredients = j.at("Ingredients").get<std::vector<ingredient>>();
        x.level = j.at("Level").get<int64_t>();
        x.modifiers = j.at("Modifiers").get<std::vector<common::types::modifier>>();
        x.engineer_craft_module = j.at("Module").get<std::string>();
        x.quality = j.at("Quality").get<double>();
        x.slot = j.at("Slot").get<std::string>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const engineer_craft & x) {
        j = json::object();
        j["ApplyExperimentalEffect"] = x.apply_experimental_effect;
        j["BlueprintID"] = x.blueprint_id;
        j["BlueprintName"] = x.blueprint_name;
        j["Engineer"] = x.engineer;
        j["EngineerID"] = x.engineer_id;
        j["event"] = x.event;
        j["ExperimentalEffect"] = x.experimental_effect;
        j["ExperimentalEffect_Localised"] = x.experimental_effect_localised;
        j["Ingredients"] = x.ingredients;
        j["Level"] = x.level;
        j["Modifiers"] = x.modifiers;
        j["Module"] = x.engineer_craft_module;
        j["Quality"] = x.quality;
        j["Slot"] = x.slot;
        j["timestamp"] = x.timestamp;
    }
}


