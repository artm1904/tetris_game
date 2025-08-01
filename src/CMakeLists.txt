cmake_minimum_required(VERSION 3.10)


add_executable(tetris_executable
    main.cpp
    Grid/grid.cpp
)

target_link_libraries(tetris_executable PRIVATE raylib)

target_compile_options(tetris_executable PRIVATE ${PROJECT_COMPILE_OPTIONS})


