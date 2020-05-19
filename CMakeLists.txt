cmake_minimum_required(VERSION 3.16)

project(GameEngine)

message(STATUS, "ENV{CXXFLAGS}, $ENV{CXXFLAGS}")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -std=c++17 ")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_LINK_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit")

# add_definitions("-DGLEW_STATIC")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Debug/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Debug/lib)

include_directories(
    ${PROJECT_SOURCE_DIR}/Lazel/include
    ${PROJECT_SOURCE_DIR}/Lazel/vendor/spdlog/include
)

link_directories(
    ${PROJECT_SOURCE_DIR}/Debug/lib
)

add_subdirectory(Lazel)
add_subdirectory(SandBox)