# Copyright 2024 Philipp Jeske
# SPDX-License-Identifier: MIT

add_library(${executable}-lib
    "calculations.h" 
    "types.h"
    "types.cpp"
    "parser.h"
)
target_include_directories(${executable}-lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(${executable}-lib PUBLIC cxx_std_23)

find_package(magic_enum REQUIRED)
target_link_libraries(${executable}-lib PRIVATE magic_enum::magic_enum)

find_package(scn REQUIRED)
target_link_libraries(${executable}-lib PUBLIC scn::scn)

add_executable(${executable} main.cpp)

target_link_libraries(${executable}
    PRIVATE ${executable}-lib
)
target_add_common_build_properties(${executable})

target_compile_features(${executable} PRIVATE cxx_std_20)

find_package(argparse REQUIRED)
target_link_libraries(${executable} PRIVATE argparse::argparse)

find_package(spdlog REQUIRED)
target_link_libraries(${executable} PRIVATE spdlog::spdlog)

if (EXISTS../data/input.txt)
    configure_file(../data/input.txt input.txt COPYONLY)
endif()