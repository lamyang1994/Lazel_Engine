cmake_minimum_required (VERSION 3.0)

aux_source_directory(. LAZEL_SRCS)

add_library(Lazel SHARED ${LAZEL_SRCS})