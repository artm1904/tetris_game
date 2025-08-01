cmake_minimum_required(VERSION 3.10)
project(tetris_game VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)




set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/contrib)


include(cmake/cpm.cmake)

CPMAddPackage(
    NAME RAYLIB
    GITHUB_REPOSITORY  raysan5/raylib 
    GIT_TAG 5.5
    VERSION 5.5 #if in repo tag is like v8.0.7 the GIT_TAG is not nesessarely
    
    SOURCE_DIR ${LIB_DIR}/raylib
)



# Устанавливаем опции компилятора для нашего проекта
set(PROJECT_COMPILE_OPTIONS)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    list(APPEND PROJECT_COMPILE_OPTIONS -Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    list(APPEND PROJECT_COMPILE_OPTIONS -O3)
endif()

add_subdirectory(src)
