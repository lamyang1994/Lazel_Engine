cmake_minimum_required (VERSION 3.16)

aux_source_directory(. LAZEL_SRCS)

add_library(Lazel SHARED ${LAZEL_SRCS})

target_precompile_headers(Lazel PRIVATE ../include/lzpch.hpp)