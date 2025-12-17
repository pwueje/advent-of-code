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
        spdlog::error(program);
        return EXIT_FAILURE;
    }

    std::filesystem::path input_file {program.get<std::string>("input")};

    if (!std::filesystem::exists(input_file))
    {
        spdlog::error("Input file does not exist: {}", input_file);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
