/**
 * @file calculations.h
 * @brief
 *
 * @author Philipp Jeske
 * @date 2025-12-10
 */

#pragma once

#include <spdlog/spdlog.h>

#include <cstdint>
#include <format>
#include <iterator>
#include <magic_enum/magic_enum.hpp>
#include <ranges>

namespace pjexx::aoc2025
{
enum class Direction
{
    Left,
    Right
};

std::ostream &operator<<(std::ostream &os, const Direction &item)
{
    os << magic_enum::enum_name(item);
    return os;
}

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

std::ostream &operator<<(std::ostream &os, const Steps &item)
{
    os << "Step {" << item.value() << "}";
    return os;
}

struct Rotation
{
    Direction direction;
    Steps step;
};

std::ostream &operator<<(std::ostream &os, const Rotation &item)
{
    os << item.direction << item.step.value();
    return os;
}

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
