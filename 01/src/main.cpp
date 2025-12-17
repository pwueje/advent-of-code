/*********************************************************************
 * @file   main.cpp
 * @brief  Advent Of Code 2025: 01
 *
 * @author Philipp Jeske
 * @date   2025-12-10
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include <spdlog/spdlog.h>

#include <argparse/argparse.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>
#include <vector>

#include "calculations.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("Advent Of Code 2025: 01");

    program.add_argument("input").help("Input file").default_value(std::string {"input.txt"});

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err)
    {
        spdlog::error(err.what());
        return EXIT_FAILURE;
    }

    std::filesystem::path input_file {program.get<std::string>("input")};

    if (!std::filesystem::exists(input_file))
    {
        spdlog::error("Input file does not exist: {}", input_file.string());
        return EXIT_FAILURE;
    }

    std::ifstream file {input_file};

    pjexx::aoc2025::Position<100> dial {50};
    auto password = pjexx::aoc2025::calculatePassword(dial, pjexx::aoc2025::parse(file));
    spdlog::info("The password is: {}", password);

    return EXIT_SUCCESS;
}
