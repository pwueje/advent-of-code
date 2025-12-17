# Copyright 2024 Philipp Jeske
# SPDX-License-Identifier: MIT
set(testname ${executable}-test)

add_executable(${testname}
    test_aoc01_calculations.cpp
    test_aoc01_parser.cpp
)

find_package(Catch2 REQUIRED)
find_package(spdlog REQUIRED)

target_link_libraries(${testname} PRIVATE
    Catch2::Catch2WithMain
    spdlog::spdlog
    ${executable}-lib
)