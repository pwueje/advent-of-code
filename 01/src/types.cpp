/**
 * @file types.cpp
 * @brief
 *
 * @author Philipp Jeske
 * @date 2025-12-17
 */

#include "types.h"

#include <magic_enum/magic_enum.hpp>
namespace pjexx::aoc2025
{
std::ostream &operator<<(std::ostream &os, const Direction &item)
{
    os << magic_enum::enum_name(item);
    return os;
}

std::ostream &operator<<(std::ostream &os, const Steps &item)
{
    os << "Step {" << item.value() << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Rotation &item)
{
    os << item.direction << item.step.value();
    return os;
}
}  // namespace pjexx::aoc2025
