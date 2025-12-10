/*********************************************************************
 * @file   main.cpp
 * @brief  Advent Of Code 2024: 01
 *
 * @author Philipp Jeske
 * @date   2025-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include <calculations.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <cstdint>
#include <span>
#include <vector>

using namespace pjexx::aoc2025;

struct TestCase {
    uint8_t initialValue;
    Direction direction;
    uint8_t step;
    uint8_t expectedValue;
};

TEST_CASE("Calculate Position")
{
    SECTION("Test right rotation without wrap around")
    {
        Position<24> pos {12};
        Rotation rot {.direction = Direction::Right, .step = Steps {5}};

        Position<24> expected {17};
        auto actual = pos + rot;

        REQUIRE(expected == actual);
    }

    SECTION("Test right rotation with wrap around")
    {
        Position<24> pos {17};
        Rotation rot {.direction = Direction::Right, .step = Steps {9}};

        Position<24> expected {2};
        auto actual = pos + rot;

        REQUIRE(expected == actual);
    }

    SECTION("Test left rotation without wrap around")
    {
        Position<24> pos {12};
        Rotation rot {.direction = Direction::Left, .step = Steps {5}};

        Position<24> expected {7};
        auto actual = pos + rot;

        REQUIRE(expected == actual);
    }

    SECTION("Test left rotation with wrap around")
    {
        Position<24> pos {9};
        Rotation rot {.direction = Direction::Left, .step = Steps {11}};

        Position<24> expected {22};
        auto actual = pos + rot;

        REQUIRE(expected == actual);
    }

    SECTION("Further Checks")
    {
        auto testCase = GENERATE(values({
            TestCase {.initialValue = 11, .direction = Direction::Right, .step = 8, .expectedValue = 19},
            TestCase {.initialValue = 19, .direction = Direction::Left, .step = 19, .expectedValue = 0},
            TestCase {.initialValue = 0, .direction = Direction::Left, .step = 1, .expectedValue = 99},
            TestCase {.initialValue = 99, .direction = Direction::Right, .step = 1, .expectedValue = 0},
            TestCase {.initialValue = 5, .direction = Direction::Left, .step = 10, .expectedValue = 95},
            TestCase {.initialValue = 95, .direction = Direction::Right, .step = 5, .expectedValue = 0},
            TestCase {.initialValue = 50, .direction = Direction::Left, .step = 68, .expectedValue = 82},
        }));

        Position<100> pos{testCase.initialValue};
        Rotation rot {.direction = testCase.direction, .step = Steps {testCase.step}};
        
        Position<100> expected {testCase.expectedValue};
        auto actual = pos + rot;

        REQUIRE(expected == actual);
    }
}

TEST_CASE("Calculate Password")
{
    SECTION("Basic Checks")
    {
        Position<24> pos {9};
        std::vector rotations {
            Rotation { .direction = Direction::Left, .step = Steps {11}},
            Rotation {.direction = Direction::Right,  .step = Steps {2}},
        };

        REQUIRE(calculatePassword(pos, std::span {rotations}) == 1);
    }

    SECTION("Test Data")
    {
        Position<100> pos {50};

        std::vector rotations {
            Rotation { .direction = Direction::Left, .step = Steps {68}},
            Rotation { .direction = Direction::Left, .step = Steps {30}},
            Rotation {.direction = Direction::Right, .step = Steps {48}},
            Rotation { .direction = Direction::Left,  .step = Steps {5}},
            Rotation {.direction = Direction::Right, .step = Steps {60}},
            Rotation { .direction = Direction::Left, .step = Steps {55}},
            Rotation { .direction = Direction::Left,  .step = Steps {1}},
            Rotation { .direction = Direction::Left, .step = Steps {99}},
            Rotation {.direction = Direction::Right, .step = Steps {14}},
            Rotation { .direction = Direction::Left, .step = Steps {82}},
        };

        REQUIRE(calculatePassword(pos, std::span {rotations}) == 3);
    }
}
