#pragma once
#include <unordered_set>
#include <unordered_map>
#include <variant>

namespace hue {
    #define RO_GET(name, ...) \
const __VA_ARGS__& get_##name() const { return name; }

#define RO_GET_VAL(name, ...) \
__VA_ARGS__ get_##name() const { return name; }

#define RO_GET_OPT(name, ...) \
const std::optional<__VA_ARGS__>& get_##name() const { return name; }

	struct module_modifier {
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

		RO_GET(label, std::string)
		RO_GET_OPT(less_is_good, int64_t)
		RO_GET_OPT(original_value, double)
		RO_GET_OPT(value, double)
		RO_GET_OPT(value_str, std::string)
		RO_GET_OPT(value_str_localised, std::string)
	};

	struct module_engineering {
		int64_t blueprint_id;
		std::string blueprint_name;
		std::optional<std::string> engineer;
		int64_t engineer_id;
		std::optional<std::string> experimental_effect;
		std::optional<std::string> experimental_effect_localised;
		int64_t level;
		std::vector<module_modifier> modifiers;
		double quality;

		RO_GET_VAL(blueprint_id, int64_t)
		RO_GET(blueprint_name, std::string)
		RO_GET_OPT(engineer, std::string)
		RO_GET_VAL(engineer_id, int64_t)
		RO_GET_OPT(experimental_effect, std::string)
		RO_GET_OPT(experimental_effect_localised, std::string)
		RO_GET_VAL(level, int64_t)
		RO_GET(modifiers, std::vector<module_modifier>)
		RO_GET_VAL(quality, double)

	};

	struct fuel_tanks {
		double main;
		double reserve;

		RO_GET_VAL(main, double)
		RO_GET_VAL(reserve, double)
	};

	struct module {

		std::optional<int64_t> ammo_in_clip;
		std::optional<int64_t> ammo_in_hopper;

		std::optional<module_engineering> engineering;
		double health;
		std::string item;
		bool on;
		int64_t priority;
		std::string slot;
		std::optional<int64_t> value;
		module() = default;

		explicit module(std::optional<int64_t> ammo_in_clip,
			std::optional<int64_t> ammo_in_hopper,
			std::optional<module_engineering> engineering,
			double health,
			std::string item,
			bool on,
			int64_t priority,
			std::string slot,
			std::optional<int64_t> value)
			: ammo_in_clip(ammo_in_clip),
			ammo_in_hopper(ammo_in_hopper),
			engineering(engineering),
			health(health),
			item(std::move(item)),
			on(on),
			priority(priority),
			slot(std::move(slot)),
			value(value)
		{
		}
		explicit module(const common::module_element& e)
			: ammo_in_clip(e.ammo_in_clip),
			ammo_in_hopper(e.ammo_in_hopper),
			health(e.health),
			item(e.item),
			on(e.on),
			priority(e.priority),
			slot(e.slot),
			value(e.value)
		{
			if (e.engineering) {
				// convert engineering → module_engineering
				module_engineering eng;
				eng.blueprint_id = e.engineering->blueprint_id;
				eng.blueprint_name = e.engineering->blueprint_name;
				eng.engineer = e.engineering->engineer;
				eng.engineer_id = e.engineering->engineer_id;
				eng.experimental_effect = e.engineering->experimental_effect;
				eng.experimental_effect_localised = e.engineering->experimental_effect_localised;
				eng.level = e.engineering->level;
				eng.quality = e.engineering->quality;

				// convert modifiers → module_modifier
				eng.modifiers.reserve(e.engineering->modifiers.size());
				for (const auto& m : e.engineering->modifiers) {
					module_modifier mm;
					mm.label = m.label;
					mm.less_is_good = m.less_is_good;
					mm.original_value = m.original_value;
					mm.value = m.value;
					mm.value_str = m.value_str;
					mm.value_str_localised = m.value_str_localised;
					eng.modifiers.push_back(std::move(mm));
				}

				engineering = std::move(eng);
			}
		}

		RO_GET_OPT(ammo_in_clip, int64_t)
		RO_GET_OPT(ammo_in_hopper, int64_t)
		RO_GET_OPT(engineering, module_engineering)
		RO_GET_VAL(health, double)
		RO_GET(item, std::string)
		RO_GET_VAL(on, bool)
		RO_GET_VAL(priority, int64_t)
		RO_GET(slot, std::string)
		RO_GET_OPT(value, int64_t)
	};

	struct suit {
		int64_t suit_id;
		std::string edmc_name;
		std::string loc_name;
		std::string name;
		std::vector<std::string> mods;
		std::optional<int> id;   // may be missing in early journal

		RO_GET_VAL(suit_id, int64_t)
		RO_GET(edmc_name, std::string)
		RO_GET(loc_name, std::string)
		RO_GET(name, std::string)
		RO_GET(mods, std::vector<std::string>)
		RO_GET_OPT(id, int)
	};

	struct suit_loadout {
		int64_t loadout_slot_id;
		suit current_suit;
		std::string name;
		std::unordered_map<std::string, std::string> slots;

		RO_GET_VAL(loadout_slot_id, int64_t)
		RO_GET(current_suit, hue::suit)
		RO_GET(name, std::string)
		RO_GET(slots, std::unordered_map<std::string,std::string>)
	};

	struct backpack_contents {
		std::unordered_map<std::string, int> component;
		std::unordered_map<std::string, int> consumable;
		std::unordered_map<std::string, int> item;
		std::unordered_map<std::string, int> data;

		RO_GET(component, std::unordered_map<std::string,int>)
		RO_GET(consumable, std::unordered_map<std::string,int>)
		RO_GET(item, std::unordered_map<std::string,int>)
		RO_GET(data, std::unordered_map<std::string,int>)
	};

	struct powerplay_info {
		std::optional<std::string> power;
		std::optional<int> rank;
		std::optional<int> merits;
		std::optional<int> votes;
		std::optional<int> time_pledged;

		RO_GET_OPT(power, std::string)
		RO_GET_OPT(rank, int)
		RO_GET_OPT(merits, int)
		RO_GET_OPT(votes, int)
		RO_GET_OPT(time_pledged, int)
	};

	struct game_state {
		// fileheader-derived
		std::optional<std::string> game_language;
		std::optional<std::string> game_version;
		std::optional<std::string> game_build;

		// general profile
		std::optional<std::string> captain;
		std::unordered_map<std::string, int> cargo;
		int64_t credits;
		std::optional<std::string> fid;
		std::optional<bool> horizons;
		bool odyssey = false;
		std::optional<int> loan;

		// materials
		std::unordered_map<std::string, int> raw;
		std::unordered_map<std::string, int> manufactured;
		std::unordered_map<std::string, int> encoded;

		// misc dictionaries
		std::unordered_map<std::string, std::variant<std::tuple<int,int>, std::string>> engineers;
		std::unordered_map<std::string, std::tuple<int, int>> rank;
		std::unordered_map<std::string, int> reputation;
		std::unordered_map<std::string, int> statistics;

		// crew/role
		std::optional<std::string> role;

		// friends
		std::unordered_set<std::string> friends;

		// ship details
		std::optional<int64_t> ship_id;
		std::optional<std::string> ship_ident;
		std::optional<std::string> ship_name;
		std::optional<std::string> ship_type;
		std::optional<int64_t> hull_value;
		std::optional<int64_t> modules_value;
		std::optional<double> unladen_mass;
		std::optional<int64_t> cargo_capacity;
		std::optional<double> max_jump_range;
		std::optional<fuel_tanks> fuel_capacity;
		std::optional<int64_t> rebuy;

		std::unordered_map<std::string, module> modules;      // you had this as none
		std::optional<std::string> cargo_json;    // raw jSON string
		std::optional<std::string> route;        // raw route.json

		// state flags
		bool is_docked = false;
		bool on_foot = false;

		// odyssey locker contents
		std::unordered_map<std::string, int> component;
		std::unordered_map<std::string, int> item;
		std::unordered_map<std::string, int> consumable;
		std::unordered_map<std::string, int> data;

		// backpack
		backpack_contents backpack;
		std::optional<std::string> backpack_json;
		std::optional<std::string> ship_locker_json;

		// suit data
		std::unordered_map<int64_t, suit> suits;           // suit_id → Suit
		std::unordered_map<int64_t, suit_loadout> suit_loadouts;  // slot → loadout
		std::optional<int64_t> suit_current;
		std::optional<int64_t> suit_loadout_current;

		// taxi/Dropship
		bool taxi;
		bool dropship;

		// galaxy/system
		std::vector<double> star_pos; // typical eLITE starpos = [x,y,z]
		std::optional<int64_t> system_address;
		std::optional<std::string> system_name;
		std::optional<int64_t> system_population;
		std::optional<std::string> body;
		std::optional<int> body_id;
		std::optional<std::string> body_type;
		std::optional<std::string> station_name;
		std::optional<std::string> station_type;
		std::optional<uint64_t> market_id;

		std::optional<std::string> nav_route;  // raw navroute json

		// powerplay
		powerplay_info power_play;

		RO_GET_OPT(game_language, std::string)
		RO_GET_OPT(game_version, std::string)
		RO_GET_OPT(game_build, std::string)

		RO_GET_OPT(captain, std::string)
		RO_GET(cargo, std::unordered_map<std::string,int>)
		RO_GET_VAL(credits, int64_t)
		RO_GET_OPT(fid, std::string)
		RO_GET_OPT(horizons, bool)
		RO_GET_VAL(odyssey, bool)
		RO_GET_OPT(loan, int)

		RO_GET(raw, std::unordered_map<std::string,int>)
		RO_GET(manufactured, std::unordered_map<std::string,int>)
		RO_GET(encoded, std::unordered_map<std::string,int>)

		RO_GET(engineers,
		    std::unordered_map<std::string,
		        std::variant<std::tuple<int,int>,std::string>>)
		RO_GET(rank, std::unordered_map<std::string,std::tuple<int,int>>)
		RO_GET(reputation, std::unordered_map<std::string,int>)
		RO_GET(statistics, std::unordered_map<std::string,int>)

		RO_GET_OPT(role, std::string)

		RO_GET(friends, std::unordered_set<std::string>)

		RO_GET_OPT(ship_id, int64_t)
		RO_GET_OPT(ship_ident, std::string)
		RO_GET_OPT(ship_name, std::string)
		RO_GET_OPT(ship_type, std::string)
		RO_GET_OPT(hull_value, int64_t)
		RO_GET_OPT(modules_value, int64_t)
		RO_GET_OPT(unladen_mass, double)
		RO_GET_OPT(cargo_capacity, int64_t)
		RO_GET_OPT(max_jump_range, double)
		RO_GET_OPT(fuel_capacity, hue::fuel_tanks)
		RO_GET_OPT(rebuy, int64_t)

		RO_GET(modules, std::unordered_map<std::string,module>)
		RO_GET_OPT(cargo_json, std::string)
		RO_GET_OPT(route, std::string)

		RO_GET_VAL(is_docked, bool)
		RO_GET_VAL(on_foot, bool)

		RO_GET(component, std::unordered_map<std::string,int>)
		RO_GET(item, std::unordered_map<std::string,int>)
		RO_GET(consumable, std::unordered_map<std::string,int>)
		RO_GET(data, std::unordered_map<std::string,int>)

		RO_GET(backpack, backpack_contents)
		RO_GET_OPT(backpack_json, std::string)
		RO_GET_OPT(ship_locker_json, std::string)

		RO_GET(suits, std::unordered_map<int64_t,suit>)
		RO_GET(suit_loadouts, std::unordered_map<int64_t,suit_loadout>)
		RO_GET_OPT(suit_current, int64_t)
		RO_GET_OPT(suit_loadout_current, int64_t)

		RO_GET_VAL(taxi, bool)
		RO_GET_VAL(dropship, bool)

		RO_GET(star_pos, std::vector<double>)
		RO_GET_OPT(system_address, int64_t)
		RO_GET_OPT(system_name, std::string)
		RO_GET_OPT(system_population, int64_t)
		RO_GET_OPT(body, std::string)
		RO_GET_OPT(body_id, int)
		RO_GET_OPT(body_type, std::string)
		RO_GET_OPT(station_name, std::string)
		RO_GET_OPT(station_type, std::string)
		RO_GET_OPT(market_id, uint64_t)

		RO_GET_OPT(nav_route, std::string)

		RO_GET(power_play, powerplay_info)
	};
}
