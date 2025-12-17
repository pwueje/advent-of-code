/**
 * @file parser.h
 * @brief
 *
 * @author Philipp Jeske
 * @date 2025-12-17
 */
/* SPDX-License-Identifier: MIT */

#pragma once

#include <scn/scan.h>

#include <coroutine>
#include <expected>
#include <filesystem>
#include <fstream>
#include <generator>
#include <string>
#include <string_view>

#include "types.h"

namespace pjexx::aoc2025
{
using namespace std::literals;

std::expected<Direction, std::string> direction_from_char(char input)
{
    if (input == 'L')
    {
        return Direction::Left;
    }
    else if (input == 'R')
    {
        return Direction::Right;
    }
    else
    {
        return std::unexpected("Unexpected Character"s);
    }
}

std::expected<Rotation, std::string> parse(std::string_view line)
{
    auto result = scn::scan<char, uint16_t>(line, "{}{}");

    if (result)
    {
        auto [directionStr, step] = result->values();

        if (auto result = direction_from_char(directionStr); result.has_value())
        {
            return Rotation {.direction = result.value(), .step = Steps {static_cast<uint8_t>(step % 100)}};
        }
        else
        {
            return std::unexpected(result.error());
        }
    }

    return std::unexpected(result.error().msg());
}

std::generator<Rotation> parse(std::istream& stream) {
    std::string line{};
    while (stream >> line)
    {
        if (auto rot = parse(line); rot.has_value())
        {
            co_yield rot.value();
        }
    }
}

}  // namespace pjexx::aoc2025
