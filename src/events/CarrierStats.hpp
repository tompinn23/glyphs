//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     carrier_stats data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    namespace types {
        struct carrier_crew {
            bool activated;
            std::optional<std::string> crew_name;
            std::string crew_role;
            std::optional<bool> enabled;
        };

        struct finance {
            int64_t available_balance;
            int64_t carrier_balance;
            int64_t reserve_balance;
            std::optional<int64_t> reserve_percent;
            std::optional<int64_t> tax_rate;
            std::optional<int64_t> tax_rate_outfitting;
            std::optional<int64_t> tax_rate_pioneersupplies;
            std::optional<int64_t> tax_rate_rearm;
            std::optional<int64_t> tax_rate_refuel;
            std::optional<int64_t> tax_rate_repair;
            std::optional<int64_t> tax_rate_shipyard;
        };

        struct module_pack {
            std::string pack_theme;
            int64_t pack_tier;
        };

        struct ship_pack {
            std::string pack_theme;
            int64_t pack_tier;
        };

        struct space_usage {
            int64_t cargo;
            int64_t cargo_space_reserved;
            int64_t crew;
            int64_t free_space;
            int64_t module_packs;
            int64_t ship_packs;
            int64_t total_capacity;
        };
    }



    /**
     * When owner opens carrier management
     */
    struct carrier_stats {
        bool allow_notorious;
        std::string callsign;
        int64_t carrier_id;
        std::optional<std::string> carrier_type;
        std::vector<types::carrier_crew> crew;
        std::string docking_access;
        std::string event;
        types::finance finance;
        int64_t fuel_level;
        double jump_range_curr;
        double jump_range_max;
        std::vector<types::module_pack> module_packs;
        std::string name;
        bool pending_decommission;
        std::vector<types::ship_pack> ship_packs;
        types::space_usage space_usage;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    namespace types {
    inline void from_json(const json & j, carrier_crew& x) {
        x.activated = j.at("Activated").get<bool>();
        x.crew_name = get_stack_optional<std::string>(j, "CrewName");
        x.crew_role = j.at("CrewRole").get<std::string>();
        x.enabled = get_stack_optional<bool>(j, "Enabled");
    }

    inline void to_json(json & j, const carrier_crew & x) {
        j = json::object();
        j["Activated"] = x.activated;
        j["CrewName"] = x.crew_name;
        j["CrewRole"] = x.crew_role;
        j["Enabled"] = x.enabled;
    }

    inline void from_json(const json & j, finance& x) {
        x.available_balance = j.at("AvailableBalance").get<int64_t>();
        x.carrier_balance = j.at("CarrierBalance").get<int64_t>();
        x.reserve_balance = j.at("ReserveBalance").get<int64_t>();
        x.reserve_percent = get_stack_optional<int64_t>(j, "ReservePercent");
        x.tax_rate = get_stack_optional<int64_t>(j, "TaxRate");
        x.tax_rate_outfitting = get_stack_optional<int64_t>(j, "TaxRate_outfitting");
        x.tax_rate_pioneersupplies = get_stack_optional<int64_t>(j, "TaxRate_pioneersupplies");
        x.tax_rate_rearm = get_stack_optional<int64_t>(j, "TaxRate_rearm");
        x.tax_rate_refuel = get_stack_optional<int64_t>(j, "TaxRate_refuel");
        x.tax_rate_repair = get_stack_optional<int64_t>(j, "TaxRate_repair");
        x.tax_rate_shipyard = get_stack_optional<int64_t>(j, "TaxRate_shipyard");
    }

    inline void to_json(json & j, const finance & x) {
        j = json::object();
        j["AvailableBalance"] = x.available_balance;
        j["CarrierBalance"] = x.carrier_balance;
        j["ReserveBalance"] = x.reserve_balance;
        j["ReservePercent"] = x.reserve_percent;
        j["TaxRate"] = x.tax_rate;
        j["TaxRate_outfitting"] = x.tax_rate_outfitting;
        j["TaxRate_pioneersupplies"] = x.tax_rate_pioneersupplies;
        j["TaxRate_rearm"] = x.tax_rate_rearm;
        j["TaxRate_refuel"] = x.tax_rate_refuel;
        j["TaxRate_repair"] = x.tax_rate_repair;
        j["TaxRate_shipyard"] = x.tax_rate_shipyard;
    }

    inline void from_json(const json & j, module_pack& x) {
        x.pack_theme = j.at("PackTheme").get<std::string>();
        x.pack_tier = j.at("PackTier").get<int64_t>();
    }

    inline void to_json(json & j, const module_pack & x) {
        j = json::object();
        j["PackTheme"] = x.pack_theme;
        j["PackTier"] = x.pack_tier;
    }

    inline void from_json(const json & j, ship_pack& x) {
        x.pack_theme = j.at("PackTheme").get<std::string>();
        x.pack_tier = j.at("PackTier").get<int64_t>();
    }

    inline void to_json(json & j, const ship_pack & x) {
        j = json::object();
        j["PackTheme"] = x.pack_theme;
        j["PackTier"] = x.pack_tier;
    }

    inline void from_json(const json & j, space_usage& x) {
        x.cargo = j.at("Cargo").get<int64_t>();
        x.cargo_space_reserved = j.at("CargoSpaceReserved").get<int64_t>();
        x.crew = j.at("Crew").get<int64_t>();
        x.free_space = j.at("FreeSpace").get<int64_t>();
        x.module_packs = j.at("ModulePacks").get<int64_t>();
        x.ship_packs = j.at("ShipPacks").get<int64_t>();
        x.total_capacity = j.at("TotalCapacity").get<int64_t>();
    }

    inline void to_json(json & j, const space_usage & x) {
        j = json::object();
        j["Cargo"] = x.cargo;
        j["CargoSpaceReserved"] = x.cargo_space_reserved;
        j["Crew"] = x.crew;
        j["FreeSpace"] = x.free_space;
        j["ModulePacks"] = x.module_packs;
        j["ShipPacks"] = x.ship_packs;
        j["TotalCapacity"] = x.total_capacity;
    }
    }
    inline void from_json(const json & j, carrier_stats& x) {
        x.allow_notorious = j.at("AllowNotorious").get<bool>();
        x.callsign = j.at("Callsign").get<std::string>();
        x.carrier_id = j.at("CarrierID").get<int64_t>();
        x.carrier_type = get_stack_optional<std::string>(j, "CarrierType");
        x.crew = j.at("Crew").get<std::vector<types::carrier_crew>>();
        x.docking_access = j.at("DockingAccess").get<std::string>();
        x.event = j.at("event").get<std::string>();
        x.finance = j.at("Finance").get<types::finance>();
        x.fuel_level = j.at("FuelLevel").get<int64_t>();
        x.jump_range_curr = j.at("JumpRangeCurr").get<double>();
        x.jump_range_max = j.at("JumpRangeMax").get<double>();
        x.module_packs = j.at("ModulePacks").get<std::vector<types::module_pack>>();
        x.name = j.at("Name").get<std::string>();
        x.pending_decommission = j.at("PendingDecommission").get<bool>();
        x.ship_packs = j.at("ShipPacks").get<std::vector<types::ship_pack>>();
        x.space_usage = j.at("SpaceUsage").get<types::space_usage>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const carrier_stats & x) {
        j = json::object();
        j["AllowNotorious"] = x.allow_notorious;
        j["Callsign"] = x.callsign;
        j["CarrierID"] = x.carrier_id;
        j["CarrierType"] = x.carrier_type;
        j["Crew"] = x.crew;
        j["DockingAccess"] = x.docking_access;
        j["event"] = x.event;
        j["Finance"] = x.finance;
        j["FuelLevel"] = x.fuel_level;
        j["JumpRangeCurr"] = x.jump_range_curr;
        j["JumpRangeMax"] = x.jump_range_max;
        j["ModulePacks"] = x.module_packs;
        j["Name"] = x.name;
        j["PendingDecommission"] = x.pending_decommission;
        j["ShipPacks"] = x.ship_packs;
        j["SpaceUsage"] = x.space_usage;
        j["timestamp"] = x.timestamp;
    }
}


