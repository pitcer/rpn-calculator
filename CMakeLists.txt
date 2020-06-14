cmake_minimum_required(VERSION 3.17)

project(project)

file(GLOB files "src/*.cpp")
add_executable(binary ${files})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -Wall \
    -Werror \
    -Wextra \
    -pedantic \
    -Wpedantic \
    -Wold-style-cast \
    -Wno-unused-parameter \
    -Wno-unused-variable \
    -finline-functions \
    -ftree-vectorize \
    -funroll-loops \
    -Ofast")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
