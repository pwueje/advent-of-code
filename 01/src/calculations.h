/**
 * @file calculations.h
 * @brief
 *
 * @author Philipp Jeske
 * @date 2025-12-10
 */
/* SPDX-License-Identifier: MIT */

#pragma once

#include <cstdint>
#include <format>
#include <iterator>
#include <ranges>

#include "types.h"

namespace pjexx::aoc2025
{

template <uint8_t MAX_VALUE>
constexpr Position<MAX_VALUE> operator+(const Position<MAX_VALUE> &position, const Rotation &rotation)
{
    auto dialValue = position.value();

    switch (rotation.direction)
    {
    case Direction::Left:
    {
        return Position<MAX_VALUE> {static_cast<uint8_t>((MAX_VALUE + dialValue - rotation.step.value()) % MAX_VALUE)};
    }
    default:
    case Direction::Right:
    {
        return Position<MAX_VALUE> {static_cast<uint8_t>((dialValue + rotation.step.value()) % MAX_VALUE)};
    }
    }
}

template <uint8_t MAX_VALUE>
int calculatePassword(const Position<MAX_VALUE> &start_position, std::ranges::input_range auto &&rotations)
{
    Position<MAX_VALUE> position {start_position};
    int password = 0;

    for (auto rotation : rotations)
    {
        position = position + rotation;
        if (position.value() == 0)
        {
            ++password;
        }
    }

    return password;
}

}  // namespace pjexx::aoc2025
