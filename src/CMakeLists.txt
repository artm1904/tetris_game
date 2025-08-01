cmake_minimum_required(VERSION 3.10)


add_executable(tetris_executable
    main.cpp
    Ball/ball.cpp
)

target_link_libraries(tetris_executable PRIVATE raylib)

target_compile_options(tetris_executable PRIVATE ${PROJECT_COMPILE_OPTIONS})


