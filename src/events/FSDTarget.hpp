//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     fsd_target data = nlohmann::json::parse(jsonString);

#pragma once

#include "common.hpp"



namespace hue {
    using nlohmann::json;



    /**
     * When written: when selecting a star system to jump to. When following a multi-jump route,
     * this will typically appear for the next star, during a jump, ie after StartJump but
     * before the FSDJump
     */
    struct fsd_target {
        std::string event;
        std::string name;
        std::optional<int64_t> remaining_jumps_in_route;
        std::string star_class;
        int64_t system_address;
        /**
         * Timestamp in UTC, ISO 8601
         */
        std::string timestamp;
    };
}

namespace hue {
    void from_json(const json & j, fsd_target & x);
    void to_json(json & j, const fsd_target & x);

    inline void from_json(const json & j, fsd_target& x) {
        x.event = j.at("event").get<std::string>();
        x.name = j.at("Name").get<std::string>();
        x.remaining_jumps_in_route = get_stack_optional<int64_t>(j, "RemainingJumpsInRoute");
        x.star_class = j.at("StarClass").get<std::string>();
        x.system_address = j.at("SystemAddress").get<int64_t>();
        x.timestamp = j.at("timestamp").get<std::string>();
    }

    inline void to_json(json & j, const fsd_target & x) {
        j = json::object();
        j["event"] = x.event;
        j["Name"] = x.name;
        j["RemainingJumpsInRoute"] = x.remaining_jumps_in_route;
        j["StarClass"] = x.star_class;
        j["SystemAddress"] = x.system_address;
        j["timestamp"] = x.timestamp;
    }
}


