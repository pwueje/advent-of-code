/**
 * @file types.h
 * @brief
 *
 * @author Philipp Jeske
 * @date 2025-12-17
 */
/* SPDX-License-Identifier: MIT */

#pragma once

#include <cstdint>
#include <ostream>

namespace pjexx::aoc2025
{
enum class Direction
{
    Left,
    Right
};

std::ostream &operator<<(std::ostream &os, const Direction &item);

class Steps
{
  public:
    constexpr explicit Steps(uint8_t value) : _value {value} {}

    constexpr auto operator<=>(const Steps &) const = default;

    constexpr uint8_t value() const { return _value; }
    constexpr explicit operator uint8_t() const { return _value; }

  private:
    const uint8_t _value;
};

std::ostream &operator<<(std::ostream &os, const Steps &item);

struct Rotation
{
    Direction direction;
    Steps step;

    constexpr auto operator<=>(const Rotation &) const = default;
};

std::ostream &operator<<(std::ostream &os, const Rotation &item);

template <uint8_t MAX_VALUE>
class Position
{
  public:
    constexpr explicit Position(uint8_t value) : _value {static_cast<uint8_t>(value % MAX_VALUE)} {}
    constexpr explicit operator uint8_t() const { return _value; }
    constexpr uint8_t value() const { return _value; }
    constexpr auto operator<=>(const Position<MAX_VALUE> &) const = default;

    constexpr uint8_t max_value() const { return MAX_VALUE; }

  private:
    uint8_t _value;
};

template <uint8_t MAX_VALUE>
std::ostream &operator<<(std::ostream &os, const Position<MAX_VALUE> &item)
{
    os << "Pos<" << static_cast<int>(MAX_VALUE) << ">{" << static_cast<int>(item.value()) << "}";
    return os;
}
}  // namespace pjexx::aoc2025
