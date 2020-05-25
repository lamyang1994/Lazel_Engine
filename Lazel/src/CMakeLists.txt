cmake_minimum_required (VERSION 3.16)

aux_source_directory(. LAZEL_SRCS)
add_library(Lazel SHARED ${LAZEL_SRCS} Platform/MacOs/MacWindow.cpp)

target_link_libraries(Lazel glfw)
target_precompile_headers(Lazel PRIVATE ../include/lzpch.hpp)