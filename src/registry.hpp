#pragma once

#include <nlohmann/json.hpp>

#include "events/factory.hpp"

struct event_parser {
    using FactoryFn = event(*)(const nlohmann::json&);
    std::unordered_map<std::string, FactoryFn> event_registry = std::unordered_map<std::string, FactoryFn>();

    event_parser();

    event parse_event(const nlohmann::json& json) {

        // Must contain the event key
        const std::string event = json.at("event").get<std::string>();

        const auto it = event_registry.find(event);
        if (it == event_registry.end())
            throw std::runtime_error("Unknown event type: " + event);

        return it->second(json);  // Create and return the event
    }

    event parse_event(const std::string& line) {
        nlohmann::json j = nlohmann::json::parse(line);

        // Must contain the event key
        const std::string event = j.at("event").get<std::string>();

        auto it = event_registry.find(event);
        if (it == event_registry.end())
            throw std::runtime_error("Unknown event type: " + event);

        return it->second(j);  // Create and return the event
    }
};