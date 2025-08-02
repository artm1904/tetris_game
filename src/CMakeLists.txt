cmake_minimum_required(VERSION 3.10)


add_executable(tetris_executable
    main.cpp
    Game/Grid/grid.cpp
    Game/Colors/colors.cpp
    Game/Block/block.cpp
    Game/Block/blocks.cpp
    Game/Block/position.cpp
    Game/game.cpp
)

target_link_libraries(tetris_executable PRIVATE raylib)

target_compile_options(tetris_executable PRIVATE ${PROJECT_COMPILE_OPTIONS})
