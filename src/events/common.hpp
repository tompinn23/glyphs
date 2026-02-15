#pragma once

#include <nlohmann/json.hpp>
#include <optional>
#include <memory>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::make_shared<T>(); else return std::make_shared<T>(j.get<T>());
        }
    };
    template <typename T>
    struct adl_serializer<std::optional<T>> {
        static void to_json(json & j, const std::optional<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::optional<T> from_json(const json & j) {
            if (j.is_null()) return std::make_optional<T>(); else return std::make_optional<T>(j.get<T>());
        }
    };
}
#endif

namespace hue {
    using nlohmann::json;

    #ifndef NLOHMANN_UNTYPED_hue_HELPER
    #define NLOHMANN_UNTYPED_hue_HELPER
    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }
    #endif

    #ifndef NLOHMANN_OPTIONAL_hue_HELPER
    #define NLOHMANN_OPTIONAL_hue_HELPER
    template <typename T>
    inline std::shared_ptr<T> get_heap_optional(const json & j, const char * property) {
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_heap_optional(const json & j, std::string property) {
        return get_heap_optional<T>(j, property.data());
    }
    template <typename T>
    inline std::optional<T> get_stack_optional(const json & j, const char * property) {
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
            return j.at(property).get<std::optional<T>>();
        }
        return std::optional<T>();
    }

    template <typename T>
    inline std::optional<T> get_stack_optional(const json & j, std::string property) {
        return get_stack_optional<T>(j, property.data());
    }
    #endif

    namespace common {

        namespace types {
            struct modifier {
                std::string label;
                /**
                 * Either 0 or 1
                 */
                std::optional<int64_t> less_is_good;
                std::optional<double> original_value;
                /**
                 * Either Value or ValueStr is used. These modification types have string values:
                 * WeaponMode, DamageType, CabinClass.
                 */
                std::optional<double> value;
                /**
                 * Either Value or ValueStr is used. These modification types have string values:
                 * WeaponMode, DamageType, CabinClass.
                 */
                std::optional<std::string> value_str;
                std::optional<std::string> value_str_localised;
            };

            /*
             * If engineered
             */
            struct engineering {
                int64_t blueprint_id;
                std::string blueprint_name;
                std::optional<std::string> engineer;
                int64_t engineer_id;
                std::optional<std::string> experimental_effect;
                std::optional<std::string> experimental_effect_localised;
                int64_t level;
                std::vector<modifier> modifiers;
                double quality;
            };

            struct faction1 {
                std::string name;
                std::string stake;
                std::optional<std::string> stake_localised;
                int64_t won_days;
            };

            struct faction2 {
                std::string name;
                std::string stake;
                int64_t won_days;
            };
        }



        struct module_element {
            /**
             * If relevant. For a passenger cabin, AmmoInClip holds the number of places in the cabin.
             */
            std::optional<int64_t> ammo_in_clip;
            /**
             * if relevant
             */
            std::optional<int64_t> ammo_in_hopper;
            /**
             * If engineered
             */
            std::optional<types::engineering> engineering;
            double health;
            /**
             * Module name - lowercase
             */
            std::string item;
            bool on;
            int64_t priority;
            /**
             * Slot name
             */
            std::string slot;
            std::optional<int64_t> value;
        };


        struct suit_module_element {
            int64_t module_class;
            std::string module_name;
            std::optional<std::string> module_name_localised;
            std::string slot_name;
            int64_t suit_module_id;
            std::vector<std::string> weapon_mods;
        };

        struct component {
            int64_t count;
            std::optional<int64_t> mission_id;
            std::string name;
            std::optional<std::string> name_localised;
            int64_t owner_id;
        };

        struct consumable {
            int64_t count;
            std::string name;
            std::optional<std::string> name_localised;
            int64_t owner_id;
        };

        struct data {
            int64_t count;
            std::optional<int64_t> mission_id;
            std::string name;
            std::optional<std::string> name_localised;
            int64_t owner_id;
        };

        struct backpack_item {
            int64_t count;
            std::optional<int64_t> mission_id;
            std::string name;
            std::optional<std::string> name_localised;
            int64_t owner_id;
        };

        struct crew {
            std::string name;
            std::string role;
        };

        struct landing_pads {
            int64_t large;
            int64_t medium;
            int64_t small;
        };

        struct station_economy {
            std::string name;
            std::optional<std::string> name_localised;
            double proportion;
        };

        struct station_faction {
            std::optional<std::string> faction_state;
            std::string name;
        };

        struct micro_resource {
            std::string category;
            int64_t count;
            std::string name;
            std::optional<std::string> name_localised;
        };

        struct conflict {
            types::faction1 faction1;
            types::faction2 faction2;
            std::string status;
            std::string war_type;
        };

        struct active_state {
            std::string state;
        };

        struct pending_state {
            std::string state;
            int64_t trend;
        };

        struct recovering_state {
            std::string state;
            int64_t trend;
        };

        struct faction {
            std::optional<std::vector<active_state>> active_states;
            std::string allegiance;
            std::string faction_state;
            std::string government;
            /**
             * If player squadron faction, and this is happiest system
             */
            std::optional<bool> happiest_system;
            std::string happiness;
            std::optional<std::string> happiness_localised;
            std::optional<bool> home_system;
            double influence;
            double my_reputation;
            std::string name;
            std::optional<std::vector<pending_state>> pending_states;
            std::optional<std::vector<recovering_state>> recovering_states;
            std::optional<bool> squadron_faction;
        };

        struct powerplay_conflict_progress {
            /**
             * Progress towards the control threshold of 120k merits. can exceed 100%(1.0).
             */
            double conflict_progress;
            std::string power;
        };

        struct system_faction {
            std::optional<std::string> faction_state;
            std::string name;
        };

        /**
         * Thargoid war information
         */
        struct thargoid_war {
            std::string current_state;
            std::optional<std::string> estimated_remaining_time;
            std::optional<std::string> next_state_failure;
            std::optional<std::string> next_state_success;
            std::optional<int64_t> remaining_ports;
            bool success_state_reached;
            std::optional<double> war_progress;
        };

        struct signal {
            int64_t count;
            std::string type;
            std::optional<std::string> type_localised;
        };
    }




}

namespace hue {

    namespace common {

        namespace types {
            inline void from_json(const json& j, modifier& x) {
                x.label = j.at("Label").get<std::string>();
                x.less_is_good = get_stack_optional<int64_t>(j, "LessIsGood");
                x.original_value = get_stack_optional<double>(j, "OriginalValue");
                x.value = get_stack_optional<double>(j, "Value");
                x.value_str = get_stack_optional<std::string>(j, "ValueStr");
                x.value_str_localised = get_stack_optional<std::string>(j, "ValueStr_Localised");
            }

            inline void to_json(json& j, const modifier& x) {
                j = json::object();
                j["Label"] = x.label;
                j["LessIsGood"] = x.less_is_good;
                j["OriginalValue"] = x.original_value;
                j["Value"] = x.value;
                j["ValueStr"] = x.value_str;
                j["ValueStr_Localised"] = x.value_str_localised;
            }

            inline void from_json(const json& j, faction1& x) {
                x.name = j.at("Name").get<std::string>();
                x.stake = j.at("Stake").get<std::string>();
                x.stake_localised = get_stack_optional<std::string>(j, "Stake_Localised");
                x.won_days = j.at("WonDays").get<int64_t>();
            }

            inline void to_json(json& j, const faction1& x) {
                j = json::object();
                j["Name"] = x.name;
                j["Stake"] = x.stake;
                j["Stake_Localised"] = x.stake_localised;
                j["WonDays"] = x.won_days;
            }

            inline void from_json(const json& j, faction2& x) {
                x.name = j.at("Name").get<std::string>();
                x.stake = j.at("Stake").get<std::string>();
                x.won_days = j.at("WonDays").get<int64_t>();
            }

            inline void to_json(json& j, const faction2& x) {
                j = json::object();
                j["Name"] = x.name;
                j["Stake"] = x.stake;
                j["WonDays"] = x.won_days;
            }


            inline void from_json(const json& j, engineering& x) {
                x.blueprint_id = j.at("BlueprintID").get<int64_t>();
                x.blueprint_name = j.at("BlueprintName").get<std::string>();
                x.engineer = get_stack_optional<std::string>(j, "Engineer");
                x.engineer_id = j.at("EngineerID").get<int64_t>();
                x.experimental_effect = get_stack_optional<std::string>(j, "ExperimentalEffect");
                x.experimental_effect_localised = get_stack_optional<std::string>(j, "ExperimentalEffect_Localised");
                x.level = j.at("Level").get<int64_t>();
                x.modifiers = j.at("Modifiers").get<std::vector<modifier>>();
                x.quality = j.at("Quality").get<double>();
            }

            inline void to_json(json& j, const engineering& x) {
                j = json::object();
                j["BlueprintID"] = x.blueprint_id;
                j["BlueprintName"] = x.blueprint_name;
                j["Engineer"] = x.engineer;
                j["EngineerID"] = x.engineer_id;
                j["ExperimentalEffect"] = x.experimental_effect;
                j["ExperimentalEffect_Localised"] = x.experimental_effect_localised;
                j["Level"] = x.level;
                j["Modifiers"] = x.modifiers;
                j["Quality"] = x.quality;
            }
        }


        inline void from_json(const json& j, suit_module_element& x) {
            x.module_class = j.at("Class").get<int64_t>();
            x.module_name = j.at("ModuleName").get<std::string>();
            x.module_name_localised = get_stack_optional<std::string>(j, "ModuleName_Localised");
            x.slot_name = j.at("SlotName").get<std::string>();
            x.suit_module_id = j.at("SuitModuleID").get<int64_t>();
            x.weapon_mods = j.at("WeaponMods").get<std::vector<std::string>>();
        }

        inline void to_json(json& j, const suit_module_element& x) {
            j = json::object();
            j["Class"] = x.module_class;
            j["ModuleName"] = x.module_name;
            j["ModuleName_Localised"] = x.module_name_localised;
            j["SlotName"] = x.slot_name;
            j["SuitModuleID"] = x.suit_module_id;
            j["WeaponMods"] = x.weapon_mods;
        }

        inline void from_json(const json& j, component& x) {
            x.count = j.at("Count").get<int64_t>();
            x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
            x.name = j.at("Name").get<std::string>();
            x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
            x.owner_id = j.at("OwnerID").get<int64_t>();
        }

        inline void to_json(json& j, const component& x) {
            j = json::object();
            j["Count"] = x.count;
            j["MissionID"] = x.mission_id;
            j["Name"] = x.name;
            j["Name_Localised"] = x.name_localised;
            j["OwnerID"] = x.owner_id;
        }

        inline void from_json(const json& j, consumable& x) {
            x.count = j.at("Count").get<int64_t>();
            x.name = j.at("Name").get<std::string>();
            x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
            x.owner_id = j.at("OwnerID").get<int64_t>();
        }

        inline void to_json(json& j, const consumable& x) {
            j = json::object();
            j["Count"] = x.count;
            j["Name"] = x.name;
            j["Name_Localised"] = x.name_localised;
            j["OwnerID"] = x.owner_id;
        }

        inline void from_json(const json& j, data& x) {
            x.count = j.at("Count").get<int64_t>();
            x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
            x.name = j.at("Name").get<std::string>();
            x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
            x.owner_id = j.at("OwnerID").get<int64_t>();
        }

        inline void to_json(json& j, const data& x) {
            j = json::object();
            j["Count"] = x.count;
            j["MissionID"] = x.mission_id;
            j["Name"] = x.name;
            j["Name_Localised"] = x.name_localised;
            j["OwnerID"] = x.owner_id;
        }

        inline void from_json(const json& j, backpack_item& x) {
            x.count = j.at("Count").get<int64_t>();
            x.mission_id = get_stack_optional<int64_t>(j, "MissionID");
            x.name = j.at("Name").get<std::string>();
            x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
            x.owner_id = j.at("OwnerID").get<int64_t>();
        }

        inline void to_json(json& j, const backpack_item& x) {
            j = json::object();
            j["Count"] = x.count;
            j["MissionID"] = x.mission_id;
            j["Name"] = x.name;
            j["Name_Localised"] = x.name_localised;
            j["OwnerID"] = x.owner_id;
        }

        inline void from_json(const json& j, signal& x) {
            x.count = j.at("Count").get<int64_t>();
            x.type = j.at("Type").get<std::string>();
            x.type_localised = get_stack_optional<std::string>(j, "Type_Localised");
        }

        inline void to_json(json& j, const signal& x) {
            j = json::object();
            j["Count"] = x.count;
            j["Type"] = x.type;
            j["Type_Localised"] = x.type_localised;
        }

        inline void from_json(const json& j, crew& x) {
            x.name = j.at("Name").get<std::string>();
            x.role = j.at("Role").get<std::string>();
        }

        inline void to_json(json& j, const crew& x) {
            j = json::object();
            j["Name"] = x.name;
            j["Role"] = x.role;
        }


        inline void from_json(const json& j, landing_pads& x) {
            x.large = j.at("Large").get<int64_t>();
            x.medium = j.at("Medium").get<int64_t>();
            x.small = j.at("Small").get<int64_t>();
        }

        inline void to_json(json& j, const landing_pads& x) {
            j = json::object();
            j["Large"] = x.large;
            j["Medium"] = x.medium;
            j["Small"] = x.small;
        }

        inline void from_json(const json& j, micro_resource& x) {
            x.category = j.at("Category").get<std::string>();
            x.count = j.at("Count").get<int64_t>();
            x.name = j.at("Name").get<std::string>();
            x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        }

        inline void to_json(json& j, const micro_resource& x) {
            j = json::object();
            j["Category"] = x.category;
            j["Count"] = x.count;
            j["Name"] = x.name;
            j["Name_Localised"] = x.name_localised;
        }

        inline void from_json(const json& j, station_economy& x) {
            x.name = j.at("Name").get<std::string>();
            x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
            x.proportion = j.at("Proportion").get<double>();
        }

        inline void to_json(json& j, const station_economy& x) {
            j = json::object();
            j["Name"] = x.name;
            j["Name_Localised"] = x.name_localised;
            j["Proportion"] = x.proportion;
        }

        inline void from_json(const json& j, station_faction& x) {
            x.faction_state = get_stack_optional<std::string>(j, "FactionState");
            x.name = j.at("Name").get<std::string>();
        }

        inline void to_json(json& j, const station_faction& x) {
            j = json::object();
            j["FactionState"] = x.faction_state;
            j["Name"] = x.name;
        }



        inline void from_json(const json& j, conflict& x) {
            x.faction1 = j.at("Faction1").get<types::faction1>();
            x.faction2 = j.at("Faction2").get<types::faction2>();
            x.status = j.at("Status").get<std::string>();
            x.war_type = j.at("WarType").get<std::string>();
        }

        inline void to_json(json& j, const conflict& x) {
            j = json::object();
            j["Faction1"] = x.faction1;
            j["Faction2"] = x.faction2;
            j["Status"] = x.status;
            j["WarType"] = x.war_type;
        }

        inline void from_json(const json& j, active_state& x) {
            x.state = j.at("State").get<std::string>();
        }

        inline void to_json(json& j, const active_state& x) {
            j = json::object();
            j["State"] = x.state;
        }

        inline void from_json(const json& j, pending_state& x) {
            x.state = j.at("State").get<std::string>();
            x.trend = j.at("Trend").get<int64_t>();
        }

        inline void to_json(json& j, const pending_state& x) {
            j = json::object();
            j["State"] = x.state;
            j["Trend"] = x.trend;
        }

        inline void from_json(const json& j, recovering_state& x) {
            x.state = j.at("State").get<std::string>();
            x.trend = j.at("Trend").get<int64_t>();
        }

        inline void to_json(json& j, const recovering_state& x) {
            j = json::object();
            j["State"] = x.state;
            j["Trend"] = x.trend;
        }

        inline void from_json(const json& j, faction& x) {
            x.active_states = get_stack_optional<std::vector<active_state>>(j, "ActiveStates");
            x.allegiance = j.at("Allegiance").get<std::string>();
            x.faction_state = j.at("FactionState").get<std::string>();
            x.government = j.at("Government").get<std::string>();
            x.happiest_system = get_stack_optional<bool>(j, "HappiestSystem");
            x.happiness = j.at("Happiness").get<std::string>();
            x.happiness_localised = get_stack_optional<std::string>(j, "Happiness_Localised");
            x.home_system = get_stack_optional<bool>(j, "HomeSystem");
            x.influence = j.at("Influence").get<double>();
            x.my_reputation = j.at("MyReputation").get<double>();
            x.name = j.at("Name").get<std::string>();
            x.pending_states = get_stack_optional<std::vector<pending_state>>(j, "PendingStates");
            x.recovering_states = get_stack_optional<std::vector<recovering_state>>(j, "RecoveringStates");
            x.squadron_faction = get_stack_optional<bool>(j, "SquadronFaction");
        }

        inline void to_json(json& j, const faction& x) {
            j = json::object();
            j["ActiveStates"] = x.active_states;
            j["Allegiance"] = x.allegiance;
            j["FactionState"] = x.faction_state;
            j["Government"] = x.government;
            j["HappiestSystem"] = x.happiest_system;
            j["Happiness"] = x.happiness;
            j["Happiness_Localised"] = x.happiness_localised;
            j["HomeSystem"] = x.home_system;
            j["Influence"] = x.influence;
            j["MyReputation"] = x.my_reputation;
            j["Name"] = x.name;
            j["PendingStates"] = x.pending_states;
            j["RecoveringStates"] = x.recovering_states;
            j["SquadronFaction"] = x.squadron_faction;
        }

        inline void from_json(const json& j, powerplay_conflict_progress& x) {
            x.conflict_progress = j.at("ConflictProgress").get<double>();
            x.power = j.at("Power").get<std::string>();
        }

        inline void to_json(json& j, const powerplay_conflict_progress& x) {
            j = json::object();
            j["ConflictProgress"] = x.conflict_progress;
            j["Power"] = x.power;
        }

        inline void from_json(const json& j, system_faction& x) {
            x.faction_state = get_stack_optional<std::string>(j, "FactionState");
            x.name = j.at("Name").get<std::string>();
        }

        inline void to_json(json& j, const system_faction& x) {
            j = json::object();
            j["FactionState"] = x.faction_state;
            j["Name"] = x.name;
        }

        inline void from_json(const json& j, thargoid_war& x) {
            x.current_state = j.at("CurrentState").get<std::string>();
            x.estimated_remaining_time = get_stack_optional<std::string>(j, "EstimatedRemainingTime");
            x.next_state_failure = get_stack_optional<std::string>(j, "NextStateFailure");
            x.next_state_success = get_stack_optional<std::string>(j, "NextStateSuccess");
            x.remaining_ports = get_stack_optional<int64_t>(j, "RemainingPorts");
            x.success_state_reached = j.at("SuccessStateReached").get<bool>();
            x.war_progress = get_stack_optional<double>(j, "WarProgress");
        }

        inline void to_json(json& j, const thargoid_war& x) {
            j = json::object();
            j["CurrentState"] = x.current_state;
            j["EstimatedRemainingTime"] = x.estimated_remaining_time;
            j["NextStateFailure"] = x.next_state_failure;
            j["NextStateSuccess"] = x.next_state_success;
            j["RemainingPorts"] = x.remaining_ports;
            j["SuccessStateReached"] = x.success_state_reached;
            j["WarProgress"] = x.war_progress;
        }



        inline void from_json(const json& j, module_element& x) {
            x.ammo_in_clip = get_stack_optional<int64_t>(j, "AmmoInClip");
            x.ammo_in_hopper = get_stack_optional<int64_t>(j, "AmmoInHopper");
            x.engineering = get_stack_optional<types::engineering>(j, "Engineering");
            x.health = j.at("Health").get<double>();
            x.item = j.at("Item").get<std::string>();
            x.on = j.at("On").get<bool>();
            x.priority = j.at("Priority").get<int64_t>();
            x.slot = j.at("Slot").get<std::string>();
            x.value = get_stack_optional<int64_t>(j, "Value");
        }

        inline void to_json(json& j, const module_element& x) {
            j = json::object();
            j["AmmoInClip"] = x.ammo_in_clip;
            j["AmmoInHopper"] = x.ammo_in_hopper;
            j["Engineering"] = x.engineering;
            j["Health"] = x.health;
            j["Item"] = x.item;
            j["On"] = x.on;
            j["Priority"] = x.priority;
            j["Slot"] = x.slot;
            j["Value"] = x.value;
        }
    }
}