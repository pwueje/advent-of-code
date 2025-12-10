/*********************************************************************
 * @file   main.cpp
 * @brief  Advent Of Code 2025: 01
 *
 * @author Philipp Jeske
 * @date   2025-12-10
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include <argparse/argparse.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>


int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("Advent Of Code 2025: 01");

    program.add_argument("input").help("Input file").default_value(std::string {"coordinates.txt"});

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err)
    {
        std::cerr << err.what() << '\n';
        std::cerr << program;
        return EXIT_FAILURE;
    }

    std::filesystem::path input_file {program.get<std::string>("input")};

    if (!std::filesystem::exists(input_file))
    {
        std::cerr << "Input file does not exist: " << input_file << '\n';
        return EXIT_FAILURE;
    }

    std::vector<int> lista;
    std::vector<int> listb;

    std::ifstream input_stream {input_file};

    int a = 0;
    int b = 0;
    while (input_stream >> a >> b)
    {
        lista.push_back(a);
        listb.push_back(b);
    }

    std::cout << "Distance between lists: " << pjexx::aoc2024::distance(lista, listb) << '\n';
    std::cout << "The similarity between both lists: " << pjexx::aoc2024::similarity(lista, listb) << '\n';

    return EXIT_SUCCESS;
}
