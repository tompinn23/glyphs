//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     codex_entry data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when a new discovery is added to the Codex
     */
    struct codex_entry {
        std::optional<int64_t> body_id;
        std::string category;
        std::optional<std::string> category_localised;
        int64_t entry_id;
        std::string event;
        /**
         * The IsNewEntry field is optional depending on the results of the scan
         */
        std::optional<bool> is_new_entry;
        std::optional<double> latitude;
        std::optional<double> longitude;
        std::string name;
        std::optional<std::string> name_localised;
        /**
         * The NearestDestination is added if within 50km of a location listed in the navigation
         * panel
         */
        std::optional<std::string> nearest_destination;
        std::optional<std::string> nearest_destination_localised;
        /**
         * The NewTraitsDiscovered field is optional depending on the results of the scan
         */
        std::optional<bool> new_traits_discovered;
        std::string region;
        std::optional<std::string> region_localised;
        std::string sub_category;
        std::optional<std::string> sub_category_localised;
        std::string system;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
        /**
         * The Traits field is only available for entries that have unlocked traits
         */
        std::optional<std::vector<std::string>> traits;
        std::optional<int64_t> voucher_amount;
    };
}

namespace hue {
    void from_json(const json & j, codex_entry & x);
    void to_json(json & j, const codex_entry & x);

    inline void from_json(const json & j, codex_entry& x) {
        x.body_id = get_stack_optional<int64_t>(j, "BodyID");
        x.category = j.at("Category").get<std::string>();
        x.category_localised = get_stack_optional<std::string>(j, "Category_Localised");
        x.entry_id = j.at("EntryID").get<int64_t>();
        x.event = j.at("event").get<std::string>();
        x.is_new_entry = get_stack_optional<bool>(j, "IsNewEntry");
        x.latitude = get_stack_optional<double>(j, "Latitude");
        x.longitude = get_stack_optional<double>(j, "Longitude");
        x.name = j.at("Name").get<std::string>();
        x.name_localised = get_stack_optional<std::string>(j, "Name_Localised");
        x.nearest_destination = get_stack_optional<std::string>(j, "NearestDestination");
        x.nearest_destination_localised = get_stack_optional<std::string>(j, "NearestDestination_Localised");
        x.new_traits_discovered = get_stack_optional<bool>(j, "NewTraitsDiscovered");
        x.region = j.at("Region").get<std::string>();
        x.region_localised = get_stack_optional<std::string>(j, "Region_Localised");
        x.sub_category = j.at("SubCategory").get<std::string>();
        x.sub_category_localised = get_stack_optional<std::string>(j, "SubCategory_Localised");
        x.system = j.at("System").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
        x.traits = get_stack_optional<std::vector<std::string>>(j, "Traits");
        x.voucher_amount = get_stack_optional<int64_t>(j, "VoucherAmount");
    }

    inline void to_json(json & j, const codex_entry & x) {
        j = json::object();
        j["BodyID"] = x.body_id;
        j["Category"] = x.category;
        j["Category_Localised"] = x.category_localised;
        j["EntryID"] = x.entry_id;
        j["event"] = x.event;
        j["IsNewEntry"] = x.is_new_entry;
        j["Latitude"] = x.latitude;
        j["Longitude"] = x.longitude;
        j["Name"] = x.name;
        j["Name_Localised"] = x.name_localised;
        j["NearestDestination"] = x.nearest_destination;
        j["NearestDestination_Localised"] = x.nearest_destination_localised;
        j["NewTraitsDiscovered"] = x.new_traits_discovered;
        j["Region"] = x.region;
        j["Region_Localised"] = x.region_localised;
        j["SubCategory"] = x.sub_category;
        j["SubCategory_Localised"] = x.sub_category_localised;
        j["System"] = x.system;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
        j["Traits"] = x.traits;
        j["VoucherAmount"] = x.voucher_amount;
    }
}


