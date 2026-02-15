//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     statistics data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include "common.hpp"



namespace hue {
    using nlohmann::json;


    namespace types {


    struct bank_account {
        int64_t current_wealth;
        int64_t insurance_claims;
        std::optional<int64_t> owned_ship_count;
        std::optional<int64_t> premium_stock_bought;
        int64_t spent_on_ammo_consumables;
        int64_t spent_on_fuel;
        int64_t spent_on_insurance;
        int64_t spent_on_outfitting;
        std::optional<int64_t> spent_on_premium_stock;
        int64_t spent_on_repairs;
        int64_t spent_on_ships;
        std::optional<int64_t> spent_on_suit_consumables;
        std::optional<int64_t> spent_on_suits;
        std::optional<int64_t> spent_on_weapons;
        std::optional<int64_t> suits_owned;
        std::optional<int64_t> weapons_owned;
    };

    struct combat {
        int64_t assassination_profits;
        int64_t assassinations;
        int64_t bounties_claimed;
        double bounty_hunting_profit;
        int64_t combat_bond_profits;
        int64_t combat_bonds;
        std::optional<int64_t> conflict_zone_high;
        std::optional<int64_t> conflict_zone_high_wins;
        std::optional<int64_t> conflict_zone_low;
        std::optional<int64_t> conflict_zone_low_wins;
        std::optional<int64_t> conflict_zone_medium;
        std::optional<int64_t> conflict_zone_medium_wins;
        std::optional<int64_t> conflict_zone_total;
        std::optional<int64_t> conflict_zone_total_wins;
        std::optional<int64_t> dropships_booked;
        std::optional<int64_t> dropships_cancelled;
        std::optional<int64_t> dropships_taken;
        int64_t highest_single_reward;
        std::optional<int64_t> on_foot_combat_bonds;
        std::optional<int64_t> on_foot_combat_bonds_profits;
        std::optional<int64_t> on_foot_scavs_killed;
        std::optional<int64_t> on_foot_ships_destroyed;
        std::optional<int64_t> on_foot_skimmers_killed;
        std::optional<int64_t> on_foot_vehicles_destroyed;
        std::optional<int64_t> settlement_conquered;
        std::optional<int64_t> settlement_defended;
        std::optional<int64_t> skimmers_killed;
    };

    struct cqc {
        std::optional<int64_t> cqc_credits_earned;
        double cqc_kd;
        int64_t cqc_kills;
        int64_t cqc_time_played;
        double cqc_wl;
    };

    struct crafting {
        int64_t count_of_used_engineers;
        std::optional<int64_t> recipes_applied;
        std::optional<int64_t> recipes_applied_on_previously_modified_modules;
        std::optional<int64_t> recipes_applied_rank_1;
        std::optional<int64_t> recipes_applied_rank_2;
        std::optional<int64_t> recipes_applied_rank_3;
        std::optional<int64_t> recipes_applied_rank_4;
        std::optional<int64_t> recipes_applied_rank_5;
        int64_t recipes_generated;
        int64_t recipes_generated_rank_1;
        int64_t recipes_generated_rank_2;
        int64_t recipes_generated_rank_3;
        int64_t recipes_generated_rank_4;
        int64_t recipes_generated_rank_5;
        std::optional<int64_t> spent_on_crafting;
        std::optional<int64_t> suit_mods_applied;
        std::optional<int64_t> suit_mods_applied_full;
        std::optional<int64_t> suits_upgraded;
        std::optional<int64_t> suits_upgraded_full;
        std::optional<int64_t> weapon_mods_applied;
        std::optional<int64_t> weapon_mods_applied_full;
        std::optional<int64_t> weapons_upgraded;
        std::optional<int64_t> weapons_upgraded_full;
    };

    struct stats_crew {
        std::optional<int64_t> npc_crew_died;
        std::optional<int64_t> npc_crew_fired;
        std::optional<int64_t> npc_crew_hired;
        std::optional<int64_t> npc_crew_total_wages;
    };

    struct crime {
        int64_t bounties_received;
        std::optional<int64_t> citizens_murdered;
        std::optional<int64_t> data_stolen;
        int64_t fines;
        std::optional<int64_t> goods_stolen;
        std::optional<int64_t> guards_murdered;
        int64_t highest_bounty;
        std::optional<int64_t> malware_uploaded;
        std::optional<int64_t> notoriety;
        std::optional<int64_t> omnipol_murdered;
        std::optional<int64_t> production_sabotage;
        std::optional<int64_t> production_theft;
        std::optional<int64_t> profiles_cloned;
        std::optional<int64_t> sample_stolen;
        std::optional<int64_t> settlements_state_shutdown;
        int64_t total_bounties;
        int64_t total_fines;
        std::optional<int64_t> total_murders;
        std::optional<int64_t> total_stolen;
        std::optional<int64_t> turrets_destroyed;
        std::optional<int64_t> turrets_overloaded;
        std::optional<int64_t> turrets_total;
        std::optional<int64_t> value_stolen_state_change;
    };

    struct exobiology {
        int64_t first_logged;
        int64_t first_logged_profits;
        int64_t organic_data;
        int64_t organic_data_profits;
        int64_t organic_genus;
        int64_t organic_genus_encountered;
        int64_t organic_planets;
        int64_t organic_species;
        int64_t organic_species_encountered;
        int64_t organic_systems;
        int64_t organic_variant_encountered;
    };

    struct exploration {
        std::optional<int64_t> efficient_scans;
        int64_t exploration_profits;
        std::optional<int64_t> first_footfalls;
        std::optional<int64_t> fuel_purchased;
        std::optional<int64_t> fuel_scooped;
        double greatest_distance_from_start;
        int64_t highest_payout;
        std::optional<int64_t> on_foot_distance_travelled;
        std::optional<int64_t> planet_footfalls;
        int64_t planets_scanned_to_level_2;
        int64_t planets_scanned_to_level_3;
        std::optional<int64_t> settlements_visited;
        std::optional<double> shuttle_distance_travelled;
        std::optional<int64_t> shuttle_journeys;
        std::optional<int64_t> spent_on_shuttles;
        int64_t systems_visited;
        int64_t time_played;
        int64_t total_hyperspace_distance;
        int64_t total_hyperspace_jumps;
    };

    using fc_distance_travelled = std::variant<double, std::string>;

    struct fleetcarrier {
        fc_distance_travelled fleetcarrier_distance_travelled;
        int64_t fleetcarrier_export_total;
        int64_t fleetcarrier_import_total;
        int64_t fleetcarrier_outfitting_profit;
        int64_t fleetcarrier_outfitting_sold;
        int64_t fleetcarrier_rearm_total;
        int64_t fleetcarrier_refuel_profit;
        int64_t fleetcarrier_refuel_total;
        int64_t fleetcarrier_repairs_total;
        int64_t fleetcarrier_shipyard_profit;
        int64_t fleetcarrier_shipyard_sold;
        int64_t fleetcarrier_stolenprofit_total;
        int64_t fleetcarrier_stolenspend_total;
        int64_t fleetcarrier_total_jumps;
        int64_t fleetcarrier_tradeprofit_total;
        int64_t fleetcarrier_tradespend_total;
        int64_t fleetcarrier_vouchers_profit;
        int64_t fleetcarrier_vouchers_redeemed;
    };

    struct material_trader_stats {
        std::optional<int64_t> assets_traded_in;
        std::optional<int64_t> assets_traded_out;
        std::optional<int64_t> encoded_materials_traded;
        std::optional<int64_t> grade_1__materials_traded;
        std::optional<int64_t> grade_2__materials_traded;
        std::optional<int64_t> grade_3__materials_traded;
        std::optional<int64_t> grade_4__materials_traded;
        std::optional<int64_t> grade_5__materials_traded;
        int64_t materials_traded;
        std::optional<int64_t> raw_materials_traded;
        int64_t trades_completed;
    };

    struct mining {
        std::optional<int64_t> materials_collected;
        int64_t mining_profits;
        int64_t quantity_mined;
    };

    struct multicrew {
        int64_t multicrew_credits_total;
        int64_t multicrew_fighter_time_total;
        int64_t multicrew_fines_total;
        int64_t multicrew_gunner_time_total;
        int64_t multicrew_time_total;
    };

    struct stats_passengers {
        std::optional<int64_t> passengers_missions_accepted;
        int64_t passengers_missions_bulk;
        int64_t passengers_missions_delivered;
        std::optional<int64_t> passengers_missions_disgruntled;
        int64_t passengers_missions_ejected;
        int64_t passengers_missions_vip;
    };

    struct stats_search_and_rescue {
        std::optional<int64_t> maglocks_opened;
        std::optional<int64_t> panels_opened;
        std::optional<int64_t> salvage_illegal_poi;
        std::optional<int64_t> salvage_illegal_settlements;
        std::optional<int64_t> salvage_legal_poi;
        std::optional<int64_t> salvage_legal_settlements;
        int64_t search_rescue_count;
        int64_t search_rescue_profit;
        int64_t search_rescue_traded;
        std::optional<int64_t> settlements_state_fire_out;
        std::optional<int64_t> settlements_state_reboot;
    };

    struct smuggling {
        double average_profit;
        int64_t black_markets_profits;
        int64_t black_markets_traded_with;
        int64_t highest_single_transaction;
        int64_t resources_smuggled;
    };

    struct squadron {
        int64_t squadron_bank_commodities_deposited_num;
        int64_t squadron_bank_commodities_deposited_value;
        int64_t squadron_bank_commodities_withdrawn_num;
        int64_t squadron_bank_commodities_withdrawn_value;
        int64_t squadron_bank_credits_deposited;
        int64_t squadron_bank_credits_withdrawn;
        int64_t squadron_bank_personal_assets_deposited_num;
        int64_t squadron_bank_personal_assets_deposited_value;
        int64_t squadron_bank_personal_assets_withdrawn_num;
        int64_t squadron_bank_personal_assets_withdrawn_value;
        int64_t squadron_bank_ships_deposited_num;
        int64_t squadron_bank_ships_deposited_value;
        int64_t squadron_leaderboard_aegis_highestcontribution;
        int64_t squadron_leaderboard_bgs_highestcontribution;
        int64_t squadron_leaderboard_bounty_highestcontribution;
        int64_t squadron_leaderboard_colonisation_contribution_highestcontribution;
        int64_t squadron_leaderboard_combat_highestcontribution;
        int64_t squadron_leaderboard_cqc_highestcontribution;
        int64_t squadron_leaderboard_exploration_highestcontribution;
        int64_t squadron_leaderboard_mining_highestcontribution;
        int64_t squadron_leaderboard_podiums;
        int64_t squadron_leaderboard_powerplay_highestcontribution;
        int64_t squadron_leaderboard_trade_highestcontribution;
        int64_t squadron_leaderboard_trade_illicit_highestcontribution;
    };

    struct tg_encounters {
        std::optional<int64_t> tg_encounter_imprint;
        std::optional<int64_t> tg_encounter_killed;
        int64_t tg_encounter_total;
        std::string tg_encounter_total_last_ship;
        std::string tg_encounter_total_last_system;
        std::string tg_encounter_total_last_timestamp;
        std::optional<int64_t> tg_encounter_wakes;
        std::optional<int64_t> tg_scout_count;
    };

    struct trading {
        std::optional<int64_t> assets_sold;
        double average_profit;
        std::optional<int64_t> data_sold;
        std::optional<int64_t> goods_sold;
        int64_t highest_single_transaction;
        int64_t market_profits;
        int64_t markets_traded_with;
        int64_t resources_traded;
    };
}

    /**
     * When written: at startup. This line contains the information displayed in the statistics
     * panel on the right side of the cockpit
     */
    struct statistics {
        types::bank_account bank_account;
        types::combat combat;
        std::optional<types::cqc> cqc;
        std::optional<types::crafting> crafting;
        std::optional<types::stats_crew> crew;
        types::crime crime;
        std::string event;
        std::optional<types::exobiology> exobiology;
        types::exploration exploration;
        std::optional<types::fleetcarrier> fleetcarrier;
        std::optional<types::material_trader_stats> material_trader_stats;
        types::mining mining;
        std::optional<types::multicrew> multicrew;
        types::stats_passengers passengers;
        types::stats_search_and_rescue search_and_rescue;
        types::smuggling smuggling;
        std::optional<types::squadron> squadron;
        std::optional<types::tg_encounters> tg_encounters;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        types::trading trading;
    };
}

namespace hue {


void from_json(const json & j, statistics & x);
void to_json(json & j, const statistics & x);
}
namespace nlohmann {
template <>
struct adl_serializer<std::variant<double, std::string>> {
    static void from_json(const json & j, std::variant<double, std::string> & x);
    static void to_json(json & j, const std::variant<double, std::string> & x);
};
}
namespace hue {
    namespace types {
    inline void from_json(const json & j, bank_account& x) {
        x.current_wealth = j.at("Current_Wealth").get<int64_t>();
        x.insurance_claims = j.at("Insurance_Claims").get<int64_t>();
        x.owned_ship_count = get_stack_optional<int64_t>(j, "Owned_Ship_Count");
        x.premium_stock_bought = get_stack_optional<int64_t>(j, "Premium_Stock_Bought");
        x.spent_on_ammo_consumables = j.at("Spent_On_Ammo_Consumables").get<int64_t>();
        x.spent_on_fuel = j.at("Spent_On_Fuel").get<int64_t>();
        x.spent_on_insurance = j.at("Spent_On_Insurance").get<int64_t>();
        x.spent_on_outfitting = j.at("Spent_On_Outfitting").get<int64_t>();
        x.spent_on_premium_stock = get_stack_optional<int64_t>(j, "Spent_On_Premium_Stock");
        x.spent_on_repairs = j.at("Spent_On_Repairs").get<int64_t>();
        x.spent_on_ships = j.at("Spent_On_Ships").get<int64_t>();
        x.spent_on_suit_consumables = get_stack_optional<int64_t>(j, "Spent_On_Suit_Consumables");
        x.spent_on_suits = get_stack_optional<int64_t>(j, "Spent_On_Suits");
        x.spent_on_weapons = get_stack_optional<int64_t>(j, "Spent_On_Weapons");
        x.suits_owned = get_stack_optional<int64_t>(j, "Suits_Owned");
        x.weapons_owned = get_stack_optional<int64_t>(j, "Weapons_Owned");
    }

    inline void to_json(json & j, const bank_account & x) {
        j = json::object();
        j["Current_Wealth"] = x.current_wealth;
        j["Insurance_Claims"] = x.insurance_claims;
        j["Owned_Ship_Count"] = x.owned_ship_count;
        j["Premium_Stock_Bought"] = x.premium_stock_bought;
        j["Spent_On_Ammo_Consumables"] = x.spent_on_ammo_consumables;
        j["Spent_On_Fuel"] = x.spent_on_fuel;
        j["Spent_On_Insurance"] = x.spent_on_insurance;
        j["Spent_On_Outfitting"] = x.spent_on_outfitting;
        j["Spent_On_Premium_Stock"] = x.spent_on_premium_stock;
        j["Spent_On_Repairs"] = x.spent_on_repairs;
        j["Spent_On_Ships"] = x.spent_on_ships;
        j["Spent_On_Suit_Consumables"] = x.spent_on_suit_consumables;
        j["Spent_On_Suits"] = x.spent_on_suits;
        j["Spent_On_Weapons"] = x.spent_on_weapons;
        j["Suits_Owned"] = x.suits_owned;
        j["Weapons_Owned"] = x.weapons_owned;
    }

    inline void from_json(const json & j, combat& x) {
        x.assassination_profits = j.at("Assassination_Profits").get<int64_t>();
        x.assassinations = j.at("Assassinations").get<int64_t>();
        x.bounties_claimed = j.at("Bounties_Claimed").get<int64_t>();
        x.bounty_hunting_profit = j.at("Bounty_Hunting_Profit").get<double>();
        x.combat_bond_profits = j.at("Combat_Bond_Profits").get<int64_t>();
        x.combat_bonds = j.at("Combat_Bonds").get<int64_t>();
        x.conflict_zone_high = get_stack_optional<int64_t>(j, "ConflictZone_High");
        x.conflict_zone_high_wins = get_stack_optional<int64_t>(j, "ConflictZone_High_Wins");
        x.conflict_zone_low = get_stack_optional<int64_t>(j, "ConflictZone_Low");
        x.conflict_zone_low_wins = get_stack_optional<int64_t>(j, "ConflictZone_Low_Wins");
        x.conflict_zone_medium = get_stack_optional<int64_t>(j, "ConflictZone_Medium");
        x.conflict_zone_medium_wins = get_stack_optional<int64_t>(j, "ConflictZone_Medium_Wins");
        x.conflict_zone_total = get_stack_optional<int64_t>(j, "ConflictZone_Total");
        x.conflict_zone_total_wins = get_stack_optional<int64_t>(j, "ConflictZone_Total_Wins");
        x.dropships_booked = get_stack_optional<int64_t>(j, "Dropships_Booked");
        x.dropships_cancelled = get_stack_optional<int64_t>(j, "Dropships_Cancelled");
        x.dropships_taken = get_stack_optional<int64_t>(j, "Dropships_Taken");
        x.highest_single_reward = j.at("Highest_Single_Reward").get<int64_t>();
        x.on_foot_combat_bonds = get_stack_optional<int64_t>(j, "OnFoot_Combat_Bonds");
        x.on_foot_combat_bonds_profits = get_stack_optional<int64_t>(j, "OnFoot_Combat_Bonds_Profits");
        x.on_foot_scavs_killed = get_stack_optional<int64_t>(j, "OnFoot_Scavs_Killed");
        x.on_foot_ships_destroyed = get_stack_optional<int64_t>(j, "OnFoot_Ships_Destroyed");
        x.on_foot_skimmers_killed = get_stack_optional<int64_t>(j, "OnFoot_Skimmers_Killed");
        x.on_foot_vehicles_destroyed = get_stack_optional<int64_t>(j, "OnFoot_Vehicles_Destroyed");
        x.settlement_conquered = get_stack_optional<int64_t>(j, "Settlement_Conquered");
        x.settlement_defended = get_stack_optional<int64_t>(j, "Settlement_Defended");
        x.skimmers_killed = get_stack_optional<int64_t>(j, "Skimmers_Killed");
    }

    inline void to_json(json & j, const combat & x) {
        j = json::object();
        j["Assassination_Profits"] = x.assassination_profits;
        j["Assassinations"] = x.assassinations;
        j["Bounties_Claimed"] = x.bounties_claimed;
        j["Bounty_Hunting_Profit"] = x.bounty_hunting_profit;
        j["Combat_Bond_Profits"] = x.combat_bond_profits;
        j["Combat_Bonds"] = x.combat_bonds;
        j["ConflictZone_High"] = x.conflict_zone_high;
        j["ConflictZone_High_Wins"] = x.conflict_zone_high_wins;
        j["ConflictZone_Low"] = x.conflict_zone_low;
        j["ConflictZone_Low_Wins"] = x.conflict_zone_low_wins;
        j["ConflictZone_Medium"] = x.conflict_zone_medium;
        j["ConflictZone_Medium_Wins"] = x.conflict_zone_medium_wins;
        j["ConflictZone_Total"] = x.conflict_zone_total;
        j["ConflictZone_Total_Wins"] = x.conflict_zone_total_wins;
        j["Dropships_Booked"] = x.dropships_booked;
        j["Dropships_Cancelled"] = x.dropships_cancelled;
        j["Dropships_Taken"] = x.dropships_taken;
        j["Highest_Single_Reward"] = x.highest_single_reward;
        j["OnFoot_Combat_Bonds"] = x.on_foot_combat_bonds;
        j["OnFoot_Combat_Bonds_Profits"] = x.on_foot_combat_bonds_profits;
        j["OnFoot_Scavs_Killed"] = x.on_foot_scavs_killed;
        j["OnFoot_Ships_Destroyed"] = x.on_foot_ships_destroyed;
        j["OnFoot_Skimmers_Killed"] = x.on_foot_skimmers_killed;
        j["OnFoot_Vehicles_Destroyed"] = x.on_foot_vehicles_destroyed;
        j["Settlement_Conquered"] = x.settlement_conquered;
        j["Settlement_Defended"] = x.settlement_defended;
        j["Skimmers_Killed"] = x.skimmers_killed;
    }

    inline void from_json(const json & j, cqc& x) {
        x.cqc_credits_earned = get_stack_optional<int64_t>(j, "CQC_Credits_Earned");
        x.cqc_kd = j.at("CQC_KD").get<double>();
        x.cqc_kills = j.at("CQC_Kills").get<int64_t>();
        x.cqc_time_played = j.at("CQC_Time_Played").get<int64_t>();
        x.cqc_wl = j.at("CQC_WL").get<double>();
    }

    inline void to_json(json & j, const cqc & x) {
        j = json::object();
        j["CQC_Credits_Earned"] = x.cqc_credits_earned;
        j["CQC_KD"] = x.cqc_kd;
        j["CQC_Kills"] = x.cqc_kills;
        j["CQC_Time_Played"] = x.cqc_time_played;
        j["CQC_WL"] = x.cqc_wl;
    }

    inline void from_json(const json & j, crafting& x) {
        x.count_of_used_engineers = j.at("Count_Of_Used_Engineers").get<int64_t>();
        x.recipes_applied = get_stack_optional<int64_t>(j, "Recipes_Applied");
        x.recipes_applied_on_previously_modified_modules = get_stack_optional<int64_t>(j, "Recipes_Applied_On_Previously_Modified_Modules");
        x.recipes_applied_rank_1 = get_stack_optional<int64_t>(j, "Recipes_Applied_Rank_1");
        x.recipes_applied_rank_2 = get_stack_optional<int64_t>(j, "Recipes_Applied_Rank_2");
        x.recipes_applied_rank_3 = get_stack_optional<int64_t>(j, "Recipes_Applied_Rank_3");
        x.recipes_applied_rank_4 = get_stack_optional<int64_t>(j, "Recipes_Applied_Rank_4");
        x.recipes_applied_rank_5 = get_stack_optional<int64_t>(j, "Recipes_Applied_Rank_5");
        x.recipes_generated = j.at("Recipes_Generated").get<int64_t>();
        x.recipes_generated_rank_1 = j.at("Recipes_Generated_Rank_1").get<int64_t>();
        x.recipes_generated_rank_2 = j.at("Recipes_Generated_Rank_2").get<int64_t>();
        x.recipes_generated_rank_3 = j.at("Recipes_Generated_Rank_3").get<int64_t>();
        x.recipes_generated_rank_4 = j.at("Recipes_Generated_Rank_4").get<int64_t>();
        x.recipes_generated_rank_5 = j.at("Recipes_Generated_Rank_5").get<int64_t>();
        x.spent_on_crafting = get_stack_optional<int64_t>(j, "Spent_On_Crafting");
        x.suit_mods_applied = get_stack_optional<int64_t>(j, "Suit_Mods_Applied");
        x.suit_mods_applied_full = get_stack_optional<int64_t>(j, "Suit_Mods_Applied_Full");
        x.suits_upgraded = get_stack_optional<int64_t>(j, "Suits_Upgraded");
        x.suits_upgraded_full = get_stack_optional<int64_t>(j, "Suits_Upgraded_Full");
        x.weapon_mods_applied = get_stack_optional<int64_t>(j, "Weapon_Mods_Applied");
        x.weapon_mods_applied_full = get_stack_optional<int64_t>(j, "Weapon_Mods_Applied_Full");
        x.weapons_upgraded = get_stack_optional<int64_t>(j, "Weapons_Upgraded");
        x.weapons_upgraded_full = get_stack_optional<int64_t>(j, "Weapons_Upgraded_Full");
    }

    inline void to_json(json & j, const crafting & x) {
        j = json::object();
        j["Count_Of_Used_Engineers"] = x.count_of_used_engineers;
        j["Recipes_Applied"] = x.recipes_applied;
        j["Recipes_Applied_On_Previously_Modified_Modules"] = x.recipes_applied_on_previously_modified_modules;
        j["Recipes_Applied_Rank_1"] = x.recipes_applied_rank_1;
        j["Recipes_Applied_Rank_2"] = x.recipes_applied_rank_2;
        j["Recipes_Applied_Rank_3"] = x.recipes_applied_rank_3;
        j["Recipes_Applied_Rank_4"] = x.recipes_applied_rank_4;
        j["Recipes_Applied_Rank_5"] = x.recipes_applied_rank_5;
        j["Recipes_Generated"] = x.recipes_generated;
        j["Recipes_Generated_Rank_1"] = x.recipes_generated_rank_1;
        j["Recipes_Generated_Rank_2"] = x.recipes_generated_rank_2;
        j["Recipes_Generated_Rank_3"] = x.recipes_generated_rank_3;
        j["Recipes_Generated_Rank_4"] = x.recipes_generated_rank_4;
        j["Recipes_Generated_Rank_5"] = x.recipes_generated_rank_5;
        j["Spent_On_Crafting"] = x.spent_on_crafting;
        j["Suit_Mods_Applied"] = x.suit_mods_applied;
        j["Suit_Mods_Applied_Full"] = x.suit_mods_applied_full;
        j["Suits_Upgraded"] = x.suits_upgraded;
        j["Suits_Upgraded_Full"] = x.suits_upgraded_full;
        j["Weapon_Mods_Applied"] = x.weapon_mods_applied;
        j["Weapon_Mods_Applied_Full"] = x.weapon_mods_applied_full;
        j["Weapons_Upgraded"] = x.weapons_upgraded;
        j["Weapons_Upgraded_Full"] = x.weapons_upgraded_full;
    }

    inline void from_json(const json & j, stats_crew& x) {
        x.npc_crew_died = get_stack_optional<int64_t>(j, "NpcCrew_Died");
        x.npc_crew_fired = get_stack_optional<int64_t>(j, "NpcCrew_Fired");
        x.npc_crew_hired = get_stack_optional<int64_t>(j, "NpcCrew_Hired");
        x.npc_crew_total_wages = get_stack_optional<int64_t>(j, "NpcCrew_TotalWages");
    }

    inline void to_json(json & j, const stats_crew & x) {
        j = json::object();
        j["NpcCrew_Died"] = x.npc_crew_died;
        j["NpcCrew_Fired"] = x.npc_crew_fired;
        j["NpcCrew_Hired"] = x.npc_crew_hired;
        j["NpcCrew_TotalWages"] = x.npc_crew_total_wages;
    }

    inline void from_json(const json & j, crime& x) {
        x.bounties_received = j.at("Bounties_Received").get<int64_t>();
        x.citizens_murdered = get_stack_optional<int64_t>(j, "Citizens_Murdered");
        x.data_stolen = get_stack_optional<int64_t>(j, "Data_Stolen");
        x.fines = j.at("Fines").get<int64_t>();
        x.goods_stolen = get_stack_optional<int64_t>(j, "Goods_Stolen");
        x.guards_murdered = get_stack_optional<int64_t>(j, "Guards_Murdered");
        x.highest_bounty = j.at("Highest_Bounty").get<int64_t>();
        x.malware_uploaded = get_stack_optional<int64_t>(j, "Malware_Uploaded");
        x.notoriety = get_stack_optional<int64_t>(j, "Notoriety");
        x.omnipol_murdered = get_stack_optional<int64_t>(j, "Omnipol_Murdered");
        x.production_sabotage = get_stack_optional<int64_t>(j, "Production_Sabotage");
        x.production_theft = get_stack_optional<int64_t>(j, "Production_Theft");
        x.profiles_cloned = get_stack_optional<int64_t>(j, "Profiles_Cloned");
        x.sample_stolen = get_stack_optional<int64_t>(j, "Sample_Stolen");
        x.settlements_state_shutdown = get_stack_optional<int64_t>(j, "Settlements_State_Shutdown");
        x.total_bounties = j.at("Total_Bounties").get<int64_t>();
        x.total_fines = j.at("Total_Fines").get<int64_t>();
        x.total_murders = get_stack_optional<int64_t>(j, "Total_Murders");
        x.total_stolen = get_stack_optional<int64_t>(j, "Total_Stolen");
        x.turrets_destroyed = get_stack_optional<int64_t>(j, "Turrets_Destroyed");
        x.turrets_overloaded = get_stack_optional<int64_t>(j, "Turrets_Overloaded");
        x.turrets_total = get_stack_optional<int64_t>(j, "Turrets_Total");
        x.value_stolen_state_change = get_stack_optional<int64_t>(j, "Value_Stolen_StateChange");
    }

    inline void to_json(json & j, const crime & x) {
        j = json::object();
        j["Bounties_Received"] = x.bounties_received;
        j["Citizens_Murdered"] = x.citizens_murdered;
        j["Data_Stolen"] = x.data_stolen;
        j["Fines"] = x.fines;
        j["Goods_Stolen"] = x.goods_stolen;
        j["Guards_Murdered"] = x.guards_murdered;
        j["Highest_Bounty"] = x.highest_bounty;
        j["Malware_Uploaded"] = x.malware_uploaded;
        j["Notoriety"] = x.notoriety;
        j["Omnipol_Murdered"] = x.omnipol_murdered;
        j["Production_Sabotage"] = x.production_sabotage;
        j["Production_Theft"] = x.production_theft;
        j["Profiles_Cloned"] = x.profiles_cloned;
        j["Sample_Stolen"] = x.sample_stolen;
        j["Settlements_State_Shutdown"] = x.settlements_state_shutdown;
        j["Total_Bounties"] = x.total_bounties;
        j["Total_Fines"] = x.total_fines;
        j["Total_Murders"] = x.total_murders;
        j["Total_Stolen"] = x.total_stolen;
        j["Turrets_Destroyed"] = x.turrets_destroyed;
        j["Turrets_Overloaded"] = x.turrets_overloaded;
        j["Turrets_Total"] = x.turrets_total;
        j["Value_Stolen_StateChange"] = x.value_stolen_state_change;
    }

    inline void from_json(const json & j, exobiology& x) {
        x.first_logged = j.at("First_Logged").get<int64_t>();
        x.first_logged_profits = j.at("First_Logged_Profits").get<int64_t>();
        x.organic_data = j.at("Organic_Data").get<int64_t>();
        x.organic_data_profits = j.at("Organic_Data_Profits").get<int64_t>();
        x.organic_genus = j.at("Organic_Genus").get<int64_t>();
        x.organic_genus_encountered = j.at("Organic_Genus_Encountered").get<int64_t>();
        x.organic_planets = j.at("Organic_Planets").get<int64_t>();
        x.organic_species = j.at("Organic_Species").get<int64_t>();
        x.organic_species_encountered = j.at("Organic_Species_Encountered").get<int64_t>();
        x.organic_systems = j.at("Organic_Systems").get<int64_t>();
        x.organic_variant_encountered = j.at("Organic_Variant_Encountered").get<int64_t>();
    }

    inline void to_json(json & j, const exobiology & x) {
        j = json::object();
        j["First_Logged"] = x.first_logged;
        j["First_Logged_Profits"] = x.first_logged_profits;
        j["Organic_Data"] = x.organic_data;
        j["Organic_Data_Profits"] = x.organic_data_profits;
        j["Organic_Genus"] = x.organic_genus;
        j["Organic_Genus_Encountered"] = x.organic_genus_encountered;
        j["Organic_Planets"] = x.organic_planets;
        j["Organic_Species"] = x.organic_species;
        j["Organic_Species_Encountered"] = x.organic_species_encountered;
        j["Organic_Systems"] = x.organic_systems;
        j["Organic_Variant_Encountered"] = x.organic_variant_encountered;
    }

    inline void from_json(const json & j, exploration& x) {
        x.efficient_scans = get_stack_optional<int64_t>(j, "Efficient_Scans");
        x.exploration_profits = j.at("Exploration_Profits").get<int64_t>();
        x.first_footfalls = get_stack_optional<int64_t>(j, "First_Footfalls");
        x.fuel_purchased = get_stack_optional<int64_t>(j, "Fuel_Purchased");
        x.fuel_scooped = get_stack_optional<int64_t>(j, "Fuel_Scooped");
        x.greatest_distance_from_start = j.at("Greatest_Distance_From_Start").get<double>();
        x.highest_payout = j.at("Highest_Payout").get<int64_t>();
        x.on_foot_distance_travelled = get_stack_optional<int64_t>(j, "OnFoot_Distance_Travelled");
        x.planet_footfalls = get_stack_optional<int64_t>(j, "Planet_Footfalls");
        x.planets_scanned_to_level_2 = j.at("Planets_Scanned_To_Level_2").get<int64_t>();
        x.planets_scanned_to_level_3 = j.at("Planets_Scanned_To_Level_3").get<int64_t>();
        x.settlements_visited = get_stack_optional<int64_t>(j, "Settlements_Visited");
        x.shuttle_distance_travelled = get_stack_optional<double>(j, "Shuttle_Distance_Travelled");
        x.shuttle_journeys = get_stack_optional<int64_t>(j, "Shuttle_Journeys");
        x.spent_on_shuttles = get_stack_optional<int64_t>(j, "Spent_On_Shuttles");
        x.systems_visited = j.at("Systems_Visited").get<int64_t>();
        x.time_played = j.at("Time_Played").get<int64_t>();
        x.total_hyperspace_distance = j.at("Total_Hyperspace_Distance").get<int64_t>();
        x.total_hyperspace_jumps = j.at("Total_Hyperspace_Jumps").get<int64_t>();
    }

    inline void to_json(json & j, const exploration & x) {
        j = json::object();
        j["Efficient_Scans"] = x.efficient_scans;
        j["Exploration_Profits"] = x.exploration_profits;
        j["First_Footfalls"] = x.first_footfalls;
        j["Fuel_Purchased"] = x.fuel_purchased;
        j["Fuel_Scooped"] = x.fuel_scooped;
        j["Greatest_Distance_From_Start"] = x.greatest_distance_from_start;
        j["Highest_Payout"] = x.highest_payout;
        j["OnFoot_Distance_Travelled"] = x.on_foot_distance_travelled;
        j["Planet_Footfalls"] = x.planet_footfalls;
        j["Planets_Scanned_To_Level_2"] = x.planets_scanned_to_level_2;
        j["Planets_Scanned_To_Level_3"] = x.planets_scanned_to_level_3;
        j["Settlements_Visited"] = x.settlements_visited;
        j["Shuttle_Distance_Travelled"] = x.shuttle_distance_travelled;
        j["Shuttle_Journeys"] = x.shuttle_journeys;
        j["Spent_On_Shuttles"] = x.spent_on_shuttles;
        j["Systems_Visited"] = x.systems_visited;
        j["Time_Played"] = x.time_played;
        j["Total_Hyperspace_Distance"] = x.total_hyperspace_distance;
        j["Total_Hyperspace_Jumps"] = x.total_hyperspace_jumps;
    }

    inline void from_json(const json & j, fleetcarrier& x) {
        x.fleetcarrier_distance_travelled = j.at("FLEETCARRIER_DISTANCE_TRAVELLED").get<types::fc_distance_travelled>();
        x.fleetcarrier_export_total = j.at("FLEETCARRIER_EXPORT_TOTAL").get<int64_t>();
        x.fleetcarrier_import_total = j.at("FLEETCARRIER_IMPORT_TOTAL").get<int64_t>();
        x.fleetcarrier_outfitting_profit = j.at("FLEETCARRIER_OUTFITTING_PROFIT").get<int64_t>();
        x.fleetcarrier_outfitting_sold = j.at("FLEETCARRIER_OUTFITTING_SOLD").get<int64_t>();
        x.fleetcarrier_rearm_total = j.at("FLEETCARRIER_REARM_TOTAL").get<int64_t>();
        x.fleetcarrier_refuel_profit = j.at("FLEETCARRIER_REFUEL_PROFIT").get<int64_t>();
        x.fleetcarrier_refuel_total = j.at("FLEETCARRIER_REFUEL_TOTAL").get<int64_t>();
        x.fleetcarrier_repairs_total = j.at("FLEETCARRIER_REPAIRS_TOTAL").get<int64_t>();
        x.fleetcarrier_shipyard_profit = j.at("FLEETCARRIER_SHIPYARD_PROFIT").get<int64_t>();
        x.fleetcarrier_shipyard_sold = j.at("FLEETCARRIER_SHIPYARD_SOLD").get<int64_t>();
        x.fleetcarrier_stolenprofit_total = j.at("FLEETCARRIER_STOLENPROFIT_TOTAL").get<int64_t>();
        x.fleetcarrier_stolenspend_total = j.at("FLEETCARRIER_STOLENSPEND_TOTAL").get<int64_t>();
        x.fleetcarrier_total_jumps = j.at("FLEETCARRIER_TOTAL_JUMPS").get<int64_t>();
        x.fleetcarrier_tradeprofit_total = j.at("FLEETCARRIER_TRADEPROFIT_TOTAL").get<int64_t>();
        x.fleetcarrier_tradespend_total = j.at("FLEETCARRIER_TRADESPEND_TOTAL").get<int64_t>();
        x.fleetcarrier_vouchers_profit = j.at("FLEETCARRIER_VOUCHERS_PROFIT").get<int64_t>();
        x.fleetcarrier_vouchers_redeemed = j.at("FLEETCARRIER_VOUCHERS_REDEEMED").get<int64_t>();
    }

    inline void to_json(json & j, const fleetcarrier & x) {
        j = json::object();
        j["FLEETCARRIER_DISTANCE_TRAVELLED"] = x.fleetcarrier_distance_travelled;
        j["FLEETCARRIER_EXPORT_TOTAL"] = x.fleetcarrier_export_total;
        j["FLEETCARRIER_IMPORT_TOTAL"] = x.fleetcarrier_import_total;
        j["FLEETCARRIER_OUTFITTING_PROFIT"] = x.fleetcarrier_outfitting_profit;
        j["FLEETCARRIER_OUTFITTING_SOLD"] = x.fleetcarrier_outfitting_sold;
        j["FLEETCARRIER_REARM_TOTAL"] = x.fleetcarrier_rearm_total;
        j["FLEETCARRIER_REFUEL_PROFIT"] = x.fleetcarrier_refuel_profit;
        j["FLEETCARRIER_REFUEL_TOTAL"] = x.fleetcarrier_refuel_total;
        j["FLEETCARRIER_REPAIRS_TOTAL"] = x.fleetcarrier_repairs_total;
        j["FLEETCARRIER_SHIPYARD_PROFIT"] = x.fleetcarrier_shipyard_profit;
        j["FLEETCARRIER_SHIPYARD_SOLD"] = x.fleetcarrier_shipyard_sold;
        j["FLEETCARRIER_STOLENPROFIT_TOTAL"] = x.fleetcarrier_stolenprofit_total;
        j["FLEETCARRIER_STOLENSPEND_TOTAL"] = x.fleetcarrier_stolenspend_total;
        j["FLEETCARRIER_TOTAL_JUMPS"] = x.fleetcarrier_total_jumps;
        j["FLEETCARRIER_TRADEPROFIT_TOTAL"] = x.fleetcarrier_tradeprofit_total;
        j["FLEETCARRIER_TRADESPEND_TOTAL"] = x.fleetcarrier_tradespend_total;
        j["FLEETCARRIER_VOUCHERS_PROFIT"] = x.fleetcarrier_vouchers_profit;
        j["FLEETCARRIER_VOUCHERS_REDEEMED"] = x.fleetcarrier_vouchers_redeemed;
    }

    inline void from_json(const json & j, material_trader_stats& x) {
        x.assets_traded_in = get_stack_optional<int64_t>(j, "Assets_Traded_In");
        x.assets_traded_out = get_stack_optional<int64_t>(j, "Assets_Traded_Out");
        x.encoded_materials_traded = get_stack_optional<int64_t>(j, "Encoded_Materials_Traded");
        x.grade_1__materials_traded = get_stack_optional<int64_t>(j, "Grade_1_Materials_Traded");
        x.grade_2__materials_traded = get_stack_optional<int64_t>(j, "Grade_2_Materials_Traded");
        x.grade_3__materials_traded = get_stack_optional<int64_t>(j, "Grade_3_Materials_Traded");
        x.grade_4__materials_traded = get_stack_optional<int64_t>(j, "Grade_4_Materials_Traded");
        x.grade_5__materials_traded = get_stack_optional<int64_t>(j, "Grade_5_Materials_Traded");
        x.materials_traded = j.at("Materials_Traded").get<int64_t>();
        x.raw_materials_traded = get_stack_optional<int64_t>(j, "Raw_Materials_Traded");
        x.trades_completed = j.at("Trades_Completed").get<int64_t>();
    }

    inline void to_json(json & j, const material_trader_stats & x) {
        j = json::object();
        j["Assets_Traded_In"] = x.assets_traded_in;
        j["Assets_Traded_Out"] = x.assets_traded_out;
        j["Encoded_Materials_Traded"] = x.encoded_materials_traded;
        j["Grade_1_Materials_Traded"] = x.grade_1__materials_traded;
        j["Grade_2_Materials_Traded"] = x.grade_2__materials_traded;
        j["Grade_3_Materials_Traded"] = x.grade_3__materials_traded;
        j["Grade_4_Materials_Traded"] = x.grade_4__materials_traded;
        j["Grade_5_Materials_Traded"] = x.grade_5__materials_traded;
        j["Materials_Traded"] = x.materials_traded;
        j["Raw_Materials_Traded"] = x.raw_materials_traded;
        j["Trades_Completed"] = x.trades_completed;
    }

    inline void from_json(const json & j, mining& x) {
        x.materials_collected = get_stack_optional<int64_t>(j, "Materials_Collected");
        x.mining_profits = j.at("Mining_Profits").get<int64_t>();
        x.quantity_mined = j.at("Quantity_Mined").get<int64_t>();
    }

    inline void to_json(json & j, const mining & x) {
        j = json::object();
        j["Materials_Collected"] = x.materials_collected;
        j["Mining_Profits"] = x.mining_profits;
        j["Quantity_Mined"] = x.quantity_mined;
    }

    inline void from_json(const json & j, multicrew& x) {
        x.multicrew_credits_total = j.at("Multicrew_Credits_Total").get<int64_t>();
        x.multicrew_fighter_time_total = j.at("Multicrew_Fighter_Time_Total").get<int64_t>();
        x.multicrew_fines_total = j.at("Multicrew_Fines_Total").get<int64_t>();
        x.multicrew_gunner_time_total = j.at("Multicrew_Gunner_Time_Total").get<int64_t>();
        x.multicrew_time_total = j.at("Multicrew_Time_Total").get<int64_t>();
    }

    inline void to_json(json & j, const multicrew & x) {
        j = json::object();
        j["Multicrew_Credits_Total"] = x.multicrew_credits_total;
        j["Multicrew_Fighter_Time_Total"] = x.multicrew_fighter_time_total;
        j["Multicrew_Fines_Total"] = x.multicrew_fines_total;
        j["Multicrew_Gunner_Time_Total"] = x.multicrew_gunner_time_total;
        j["Multicrew_Time_Total"] = x.multicrew_time_total;
    }

    inline void from_json(const json & j, stats_passengers& x) {
        x.passengers_missions_accepted = get_stack_optional<int64_t>(j, "Passengers_Missions_Accepted");
        x.passengers_missions_bulk = j.at("Passengers_Missions_Bulk").get<int64_t>();
        x.passengers_missions_delivered = j.at("Passengers_Missions_Delivered").get<int64_t>();
        x.passengers_missions_disgruntled = get_stack_optional<int64_t>(j, "Passengers_Missions_Disgruntled");
        x.passengers_missions_ejected = j.at("Passengers_Missions_Ejected").get<int64_t>();
        x.passengers_missions_vip = j.at("Passengers_Missions_VIP").get<int64_t>();
    }

    inline void to_json(json & j, const stats_passengers & x) {
        j = json::object();
        j["Passengers_Missions_Accepted"] = x.passengers_missions_accepted;
        j["Passengers_Missions_Bulk"] = x.passengers_missions_bulk;
        j["Passengers_Missions_Delivered"] = x.passengers_missions_delivered;
        j["Passengers_Missions_Disgruntled"] = x.passengers_missions_disgruntled;
        j["Passengers_Missions_Ejected"] = x.passengers_missions_ejected;
        j["Passengers_Missions_VIP"] = x.passengers_missions_vip;
    }

    inline void from_json(const json & j, stats_search_and_rescue& x) {
        x.maglocks_opened = get_stack_optional<int64_t>(j, "Maglocks_Opened");
        x.panels_opened = get_stack_optional<int64_t>(j, "Panels_Opened");
        x.salvage_illegal_poi = get_stack_optional<int64_t>(j, "Salvage_Illegal_POI");
        x.salvage_illegal_settlements = get_stack_optional<int64_t>(j, "Salvage_Illegal_Settlements");
        x.salvage_legal_poi = get_stack_optional<int64_t>(j, "Salvage_Legal_POI");
        x.salvage_legal_settlements = get_stack_optional<int64_t>(j, "Salvage_Legal_Settlements");
        x.search_rescue_count = j.at("SearchRescue_Count").get<int64_t>();
        x.search_rescue_profit = j.at("SearchRescue_Profit").get<int64_t>();
        x.search_rescue_traded = j.at("SearchRescue_Traded").get<int64_t>();
        x.settlements_state_fire_out = get_stack_optional<int64_t>(j, "Settlements_State_FireOut");
        x.settlements_state_reboot = get_stack_optional<int64_t>(j, "Settlements_State_Reboot");
    }

    inline void to_json(json & j, const stats_search_and_rescue & x) {
        j = json::object();
        j["Maglocks_Opened"] = x.maglocks_opened;
        j["Panels_Opened"] = x.panels_opened;
        j["Salvage_Illegal_POI"] = x.salvage_illegal_poi;
        j["Salvage_Illegal_Settlements"] = x.salvage_illegal_settlements;
        j["Salvage_Legal_POI"] = x.salvage_legal_poi;
        j["Salvage_Legal_Settlements"] = x.salvage_legal_settlements;
        j["SearchRescue_Count"] = x.search_rescue_count;
        j["SearchRescue_Profit"] = x.search_rescue_profit;
        j["SearchRescue_Traded"] = x.search_rescue_traded;
        j["Settlements_State_FireOut"] = x.settlements_state_fire_out;
        j["Settlements_State_Reboot"] = x.settlements_state_reboot;
    }

    inline void from_json(const json & j, smuggling& x) {
        x.average_profit = j.at("Average_Profit").get<double>();
        x.black_markets_profits = j.at("Black_Markets_Profits").get<int64_t>();
        x.black_markets_traded_with = j.at("Black_Markets_Traded_With").get<int64_t>();
        x.highest_single_transaction = j.at("Highest_Single_Transaction").get<int64_t>();
        x.resources_smuggled = j.at("Resources_Smuggled").get<int64_t>();
    }

    inline void to_json(json & j, const smuggling & x) {
        j = json::object();
        j["Average_Profit"] = x.average_profit;
        j["Black_Markets_Profits"] = x.black_markets_profits;
        j["Black_Markets_Traded_With"] = x.black_markets_traded_with;
        j["Highest_Single_Transaction"] = x.highest_single_transaction;
        j["Resources_Smuggled"] = x.resources_smuggled;
    }

    inline void from_json(const json & j, squadron& x) {
        x.squadron_bank_commodities_deposited_num = j.at("Squadron_Bank_Commodities_Deposited_Num").get<int64_t>();
        x.squadron_bank_commodities_deposited_value = j.at("Squadron_Bank_Commodities_Deposited_Value").get<int64_t>();
        x.squadron_bank_commodities_withdrawn_num = j.at("Squadron_Bank_Commodities_Withdrawn_Num").get<int64_t>();
        x.squadron_bank_commodities_withdrawn_value = j.at("Squadron_Bank_Commodities_Withdrawn_Value").get<int64_t>();
        x.squadron_bank_credits_deposited = j.at("Squadron_Bank_Credits_Deposited").get<int64_t>();
        x.squadron_bank_credits_withdrawn = j.at("Squadron_Bank_Credits_Withdrawn").get<int64_t>();
        x.squadron_bank_personal_assets_deposited_num = j.at("Squadron_Bank_PersonalAssets_Deposited_Num").get<int64_t>();
        x.squadron_bank_personal_assets_deposited_value = j.at("Squadron_Bank_PersonalAssets_Deposited_Value").get<int64_t>();
        x.squadron_bank_personal_assets_withdrawn_num = j.at("Squadron_Bank_PersonalAssets_Withdrawn_Num").get<int64_t>();
        x.squadron_bank_personal_assets_withdrawn_value = j.at("Squadron_Bank_PersonalAssets_Withdrawn_Value").get<int64_t>();
        x.squadron_bank_ships_deposited_num = j.at("Squadron_Bank_Ships_Deposited_Num").get<int64_t>();
        x.squadron_bank_ships_deposited_value = j.at("Squadron_Bank_Ships_Deposited_Value").get<int64_t>();
        x.squadron_leaderboard_aegis_highestcontribution = j.at("Squadron_Leaderboard_aegis_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_bgs_highestcontribution = j.at("Squadron_Leaderboard_bgs_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_bounty_highestcontribution = j.at("Squadron_Leaderboard_bounty_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_colonisation_contribution_highestcontribution = j.at("Squadron_Leaderboard_colonisation_contribution_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_combat_highestcontribution = j.at("Squadron_Leaderboard_combat_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_cqc_highestcontribution = j.at("Squadron_Leaderboard_cqc_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_exploration_highestcontribution = j.at("Squadron_Leaderboard_exploration_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_mining_highestcontribution = j.at("Squadron_Leaderboard_mining_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_podiums = j.at("Squadron_Leaderboard_podiums").get<int64_t>();
        x.squadron_leaderboard_powerplay_highestcontribution = j.at("Squadron_Leaderboard_powerplay_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_trade_highestcontribution = j.at("Squadron_Leaderboard_trade_highestcontribution").get<int64_t>();
        x.squadron_leaderboard_trade_illicit_highestcontribution = j.at("Squadron_Leaderboard_trade_illicit_highestcontribution").get<int64_t>();
    }

    inline void to_json(json & j, const squadron & x) {
        j = json::object();
        j["Squadron_Bank_Commodities_Deposited_Num"] = x.squadron_bank_commodities_deposited_num;
        j["Squadron_Bank_Commodities_Deposited_Value"] = x.squadron_bank_commodities_deposited_value;
        j["Squadron_Bank_Commodities_Withdrawn_Num"] = x.squadron_bank_commodities_withdrawn_num;
        j["Squadron_Bank_Commodities_Withdrawn_Value"] = x.squadron_bank_commodities_withdrawn_value;
        j["Squadron_Bank_Credits_Deposited"] = x.squadron_bank_credits_deposited;
        j["Squadron_Bank_Credits_Withdrawn"] = x.squadron_bank_credits_withdrawn;
        j["Squadron_Bank_PersonalAssets_Deposited_Num"] = x.squadron_bank_personal_assets_deposited_num;
        j["Squadron_Bank_PersonalAssets_Deposited_Value"] = x.squadron_bank_personal_assets_deposited_value;
        j["Squadron_Bank_PersonalAssets_Withdrawn_Num"] = x.squadron_bank_personal_assets_withdrawn_num;
        j["Squadron_Bank_PersonalAssets_Withdrawn_Value"] = x.squadron_bank_personal_assets_withdrawn_value;
        j["Squadron_Bank_Ships_Deposited_Num"] = x.squadron_bank_ships_deposited_num;
        j["Squadron_Bank_Ships_Deposited_Value"] = x.squadron_bank_ships_deposited_value;
        j["Squadron_Leaderboard_aegis_highestcontribution"] = x.squadron_leaderboard_aegis_highestcontribution;
        j["Squadron_Leaderboard_bgs_highestcontribution"] = x.squadron_leaderboard_bgs_highestcontribution;
        j["Squadron_Leaderboard_bounty_highestcontribution"] = x.squadron_leaderboard_bounty_highestcontribution;
        j["Squadron_Leaderboard_colonisation_contribution_highestcontribution"] = x.squadron_leaderboard_colonisation_contribution_highestcontribution;
        j["Squadron_Leaderboard_combat_highestcontribution"] = x.squadron_leaderboard_combat_highestcontribution;
        j["Squadron_Leaderboard_cqc_highestcontribution"] = x.squadron_leaderboard_cqc_highestcontribution;
        j["Squadron_Leaderboard_exploration_highestcontribution"] = x.squadron_leaderboard_exploration_highestcontribution;
        j["Squadron_Leaderboard_mining_highestcontribution"] = x.squadron_leaderboard_mining_highestcontribution;
        j["Squadron_Leaderboard_podiums"] = x.squadron_leaderboard_podiums;
        j["Squadron_Leaderboard_powerplay_highestcontribution"] = x.squadron_leaderboard_powerplay_highestcontribution;
        j["Squadron_Leaderboard_trade_highestcontribution"] = x.squadron_leaderboard_trade_highestcontribution;
        j["Squadron_Leaderboard_trade_illicit_highestcontribution"] = x.squadron_leaderboard_trade_illicit_highestcontribution;
    }

    inline void from_json(const json & j, tg_encounters& x) {
        x.tg_encounter_imprint = get_stack_optional<int64_t>(j, "TG_ENCOUNTER_IMPRINT");
        x.tg_encounter_killed = get_stack_optional<int64_t>(j, "TG_ENCOUNTER_KILLED");
        x.tg_encounter_total = j.at("TG_ENCOUNTER_TOTAL").get<int64_t>();
        x.tg_encounter_total_last_ship = j.at("TG_ENCOUNTER_TOTAL_LAST_SHIP").get<std::string>();
        x.tg_encounter_total_last_system = j.at("TG_ENCOUNTER_TOTAL_LAST_SYSTEM").get<std::string>();
        x.tg_encounter_total_last_timestamp = j.at("TG_ENCOUNTER_TOTAL_LAST_TIMESTAMP").get<std::string>();
        x.tg_encounter_wakes = get_stack_optional<int64_t>(j, "TG_ENCOUNTER_WAKES");
        x.tg_scout_count = get_stack_optional<int64_t>(j, "TG_SCOUT_COUNT");
    }

    inline void to_json(json & j, const tg_encounters & x) {
        j = json::object();
        j["TG_ENCOUNTER_IMPRINT"] = x.tg_encounter_imprint;
        j["TG_ENCOUNTER_KILLED"] = x.tg_encounter_killed;
        j["TG_ENCOUNTER_TOTAL"] = x.tg_encounter_total;
        j["TG_ENCOUNTER_TOTAL_LAST_SHIP"] = x.tg_encounter_total_last_ship;
        j["TG_ENCOUNTER_TOTAL_LAST_SYSTEM"] = x.tg_encounter_total_last_system;
        j["TG_ENCOUNTER_TOTAL_LAST_TIMESTAMP"] = x.tg_encounter_total_last_timestamp;
        j["TG_ENCOUNTER_WAKES"] = x.tg_encounter_wakes;
        j["TG_SCOUT_COUNT"] = x.tg_scout_count;
    }

    inline void from_json(const json & j, trading& x) {
        x.assets_sold = get_stack_optional<int64_t>(j, "Assets_Sold");
        x.average_profit = j.at("Average_Profit").get<double>();
        x.data_sold = get_stack_optional<int64_t>(j, "Data_Sold");
        x.goods_sold = get_stack_optional<int64_t>(j, "Goods_Sold");
        x.highest_single_transaction = j.at("Highest_Single_Transaction").get<int64_t>();
        x.market_profits = j.at("Market_Profits").get<int64_t>();
        x.markets_traded_with = j.at("Markets_Traded_With").get<int64_t>();
        x.resources_traded = j.at("Resources_Traded").get<int64_t>();
    }

    inline void to_json(json & j, const trading & x) {
        j = json::object();
        j["Assets_Sold"] = x.assets_sold;
        j["Average_Profit"] = x.average_profit;
        j["Data_Sold"] = x.data_sold;
        j["Goods_Sold"] = x.goods_sold;
        j["Highest_Single_Transaction"] = x.highest_single_transaction;
        j["Market_Profits"] = x.market_profits;
        j["Markets_Traded_With"] = x.markets_traded_with;
        j["Resources_Traded"] = x.resources_traded;
    }

    }

    inline void from_json(const json & j, statistics& x) {
        x.bank_account = j.at("Bank_Account").get<types::bank_account>();
        x.combat = j.at("Combat").get<types::combat>();
        x.cqc = get_stack_optional<types::cqc>(j, "CQC");
        x.crafting = get_stack_optional<types::crafting>(j, "Crafting");
        x.crew = get_stack_optional<types::stats_crew>(j, "Crew");
        x.crime = j.at("Crime").get<types::crime>();
        x.event = j.at("event").get<std::string>();
        x.exobiology = get_stack_optional<types::exobiology>(j, "Exobiology");
        x.exploration = j.at("Exploration").get<types::exploration>();
        x.fleetcarrier = get_stack_optional<types::fleetcarrier>(j, "FLEETCARRIER");
        x.material_trader_stats = get_stack_optional<types::material_trader_stats>(j, "Material_Trader_Stats");
        x.mining = j.at("Mining").get<types::mining>();
        x.multicrew = get_stack_optional<types::multicrew>(j, "Multicrew");
        x.passengers = j.at("Passengers").get<types::stats_passengers>();
        x.search_and_rescue = j.at("Search_And_Rescue").get<types::stats_search_and_rescue>();
        x.smuggling = j.at("Smuggling").get<types::smuggling>();
        x.squadron = get_stack_optional<types::squadron>(j, "Squadron");
        x.tg_encounters = get_stack_optional<types::tg_encounters>(j, "TG_ENCOUNTERS");
        x.timestamp = j.at("timestamp").get<std::string>();
        x.trading = j.at("Trading").get<types::trading>();
    }


    inline void to_json(json & j, const statistics & x) {
        j = json::object();
        j["Bank_Account"] = x.bank_account;
        j["Combat"] = x.combat;
        j["CQC"] = x.cqc;
        j["Crafting"] = x.crafting;
        j["Crew"] = x.crew;
        j["Crime"] = x.crime;
        j["event"] = x.event;
        j["Exobiology"] = x.exobiology;
        j["Exploration"] = x.exploration;
        j["FLEETCARRIER"] = x.fleetcarrier;
        j["Material_Trader_Stats"] = x.material_trader_stats;
        j["Mining"] = x.mining;
        j["Multicrew"] = x.multicrew;
        j["Passengers"] = x.passengers;
        j["Search_And_Rescue"] = x.search_and_rescue;
        j["Smuggling"] = x.smuggling;
        j["Squadron"] = x.squadron;
        j["TG_ENCOUNTERS"] = x.tg_encounters;
        j["timestamp"] = x.timestamp;
        j["Trading"] = x.trading;
    }
}
namespace nlohmann {
    inline void adl_serializer<std::variant<double, std::string>>::from_json(const json & j, std::variant<double, std::string> & x) {
        if (j.is_number())
            x = j.get<double>();
        else if (j.is_string())
            x = j.get<std::string>();
        else throw std::runtime_error("Could not deserialise!");
    }

    inline void adl_serializer<std::variant<double, std::string>>::to_json(json & j, const std::variant<double, std::string> & x) {
        switch (x.index()) {
            case 0:
                j = std::get<double>(x);
                break;
            case 1:
                j = std::get<std::string>(x);
                break;
            default: throw std::runtime_error("Input JSON does not conform to schema!");
        }
    }
}


