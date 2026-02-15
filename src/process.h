#pragma once
#include <cstdint>
#include <optional>
#include <string>

struct process {
    std::optional<uint32_t> pid;
    std::string journal_dir;

    explicit process(const std::string &journal_dir);

    bool running();

};

