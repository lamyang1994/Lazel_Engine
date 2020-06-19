cmake_minimum_required(VERSION 3.16)

project(GameEngine)

message(STATUS, "ENV{CXXFLAGS}, $ENV{CXXFLAGS}")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -std=c++17 -framework Cocoa -framework OpenGL -framework IOKit")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wno-unused-command-line-argument -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

if (CMAKE_BUILD_TYPE STREQUAL Debug) 
    add_definitions("-DLZ_ENABLE_ASSERT")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Debug/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Debug/lib)

include_directories(
    ${PROJECT_SOURCE_DIR}/Lazel/include
    ${PROJECT_SOURCE_DIR}/Lazel/vendor/spdlog/include
    ${PROJECT_SOURCE_DIR}/Lazel/vendor/glfw/include
    ${PROJECT_SOURCE_DIR}/Lazel/vendor/glad/include
)

link_directories(
    ${PROJECT_SOURCE_DIR}/Debug/lib
)

add_subdirectory(Lazel)
add_subdirectory(SandBox)