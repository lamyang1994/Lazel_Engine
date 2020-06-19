cmake_minimum_required (VERSION 3.16)

add_definitions(
    "-DGLFW_INCLUDE_NONE"
)

aux_source_directory(. LAZEL_SRCS)
add_library(Lazel SHARED ${LAZEL_SRCS} Platform/MacOs/MacWindow.cpp)

target_link_libraries(Lazel glfw glad)
target_precompile_headers(Lazel PRIVATE ../include/lzpch.hpp)