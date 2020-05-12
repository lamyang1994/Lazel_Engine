cmake_minimum_required (VERSION 3.0)

aux_source_directory(. APP_SRCS)

add_executable(App.o ${APP_SRCS})

target_link_libraries(App.o Lazel)