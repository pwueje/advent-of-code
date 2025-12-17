/*********************************************************************
 * @file   test_aoc01_parser.cpp
 * @brief
 *
 * @author Philipp Jeske
 * @date   2025-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include <parser.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <cstdint>
#include <ranges>
#include <span>
#include <sstream>
#include <vector>

using namespace pjexx::aoc2025;

TEST_CASE("Test direction from char")
{
    SECTION("Test Left") { REQUIRE(direction_from_char('L') == Direction::Left); }
    SECTION("Test Right") { REQUIRE(direction_from_char('R') == Direction::Right); }
    SECTION("Test Right") { REQUIRE(!direction_from_char('X').has_value()); }
}

TEST_CASE("Test parse line")
{
    SECTION("Happy Path")
    {
        constexpr std::string_view input = "R58"sv;
        Rotation expected {.direction = Direction::Right, .step = Steps {static_cast<uint8_t>(58)}};
        auto actual = parse(input);

        REQUIRE(actual == expected);
    }

    SECTION("Wrong Direction")
    {
        constexpr std::string_view input = "r58"sv;

        auto actual = parse(input);

        REQUIRE(!actual.has_value());
    }

    SECTION("Invalid Format")
    {
        constexpr std::string_view input = "58R"sv;

        auto actual = parse(input);

        REQUIRE(!actual.has_value());
    }

    SECTION("Too big input")
    {
        constexpr std::string_view input = "L266"sv;

        auto actual = parse(input);

        REQUIRE(!actual.has_value());
    }
}

TEST_CASE("Parse from stream")
{
    std::stringstream input;
    input << "L12" << std::endl;
    input << "R43" << std::endl;

    std::vector<Rotation> expectation {
        Rotation {.direction = Direction::Left, .step = Steps{12}},
        Rotation {.direction = Direction::Right, .step = Steps{43}},
    };

    for (auto [actual, expected] : std::views::zip(parse(input), expectation))
    {
        REQUIRE(actual == expected);
    }
}
