cmake_minimum_required(VERSION 3.10)
project(poboy)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)

if(MSVC)
    message(FATAL_ERROR "MSVC not supported")
else()
    add_compile_options("-Werror" "-Wall" "-Wextra")
    add_compile_options(
        "-std=c99"
        "-pedantic"
        "-fvisibility=hidden")
endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(include)
add_executable(${CMAKE_PROJECT_NAME}
    src/poboy.c)

target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES})
