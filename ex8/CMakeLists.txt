cmake_minimum_required(VERSION 3.5)

project(ex8)

find_package(IrrKlang REQUIRED CONFIG)

include_directories(${IrrKlang_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${IrrKlang_LIBRARY})