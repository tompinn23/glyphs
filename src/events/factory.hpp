#pragma once

#include "nlohmann/json.hpp"

#include "common.hpp"

namespace hue {
    struct empty {};

    inline void to_json(json &j, const empty& x) {
        j = json::object();
    }
}
struct event {
    struct Concept {
        nlohmann::json raw;          // <-- Store raw JSON here
        virtual ~Concept() = default;
        virtual const std::type_info& type() const = 0;
        virtual const nlohmann::json& serialize() = 0;
    };

    template<class T>
    struct Model : Concept {
        T value;

        Model(T&& v, nlohmann::json json)
            : value(std::move(v))
        {
            this->raw = std::move(json);
        }

        const std::type_info& type() const override { return typeid(T); }

        const nlohmann::json& serialize() override {
            using namespace hue;
            nlohmann::json json;
            to_json(json, value);
            this->raw = std::move(json);
            return this->raw;
        }
    };

    std::unique_ptr<Concept> ptr;

    event() : event(hue::empty{}, nlohmann::json{}) {}

    template<class T>
    event(T v, nlohmann::json raw_json)
        : ptr(std::make_unique<Model<T>>(std::move(v), std::move(raw_json)))
    {}

    template<class T>
    T* get_if() const {
        if (ptr->type() == typeid(T))
            return &static_cast<Model<T>*>(ptr.get())->value;
        return nullptr;
    }

    template<class T>
    bool is() const {
        return ptr->type() == typeid(T);
    }

    template<class T>
    T& get() {
        return static_cast<Model<T>*>(ptr.get())->value;
    }

    explicit operator bool() const {
        return ptr->type() != typeid(hue::empty);
    }

    const nlohmann::json& serialize() {
        return ptr->serialize();
    }

    const nlohmann::json& json() const {
        return ptr->raw;
    }
};

template <class T>
event make_event(const nlohmann::json& j) {
    T e;
    from_json(j, e);
    return event(std::move(e), std::move(j));
}