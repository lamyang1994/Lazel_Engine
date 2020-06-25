cmake_minimum_required (VERSION 3.16)

add_definitions(
    "-DGLFW_INCLUDE_NONE"
    "-DLZ_ENABLE_ASSERT"
)

aux_source_directory(Lazel/ LAZEL_SRCS)
aux_source_directory(Lazel/ImGui LAZEL_SRCS)
aux_source_directory(../vendor/imgui/ ImGui_SRCS)
aux_source_directory(Platform/MacOs/ MacOS_SRCS)
add_library(Lazel SHARED ${LAZEL_SRCS} ${MacOS_SRCS} ${OpenGL_SRCS} ${ImGui_SRCS})

target_link_libraries(Lazel glfw glad)
target_precompile_headers(Lazel PRIVATE ../include/lzpch.hpp)