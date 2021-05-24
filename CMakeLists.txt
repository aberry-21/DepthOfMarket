cmake_minimum_required(VERSION 3.13)

project(depth_of_market VERSION 1.0 LANGUAGES CXX)

add_compile_options("-std=c++2a")

add_compile_options(
    -Werror
    -Wall
    -Wextra
)

set(Boost_INCLUDE_DIR  /Users/aberry/.brew/Cellar/boost/1.75.0_3/include)
set(Boost_LIBRARY_DIR /Users/aberry/.brew/Cellar/boost/1.75.0_3/lib/)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

aux_source_directory(src DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS} src/DepthOfMarket.cc src/main.cc)

target_include_directories(${PROJECT_NAME} PUBLIC .)