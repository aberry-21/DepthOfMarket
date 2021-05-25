cmake_minimum_required(VERSION 3.13)

project(depth_of_market VERSION 1.0 LANGUAGES CXX)

add_compile_options("-std=c++2a")

add_compile_options(
    -Werror
    -Wall
    -Wextra
)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

aux_source_directory(src DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS} src/DepthOfMarket.cc src/main.cc includes/LogDuration.h)

target_include_directories(${PROJECT_NAME} PUBLIC .)