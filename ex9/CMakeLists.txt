cmake_minimum_required(VERSION 3.5)

project(ex9)

find_package(Irrlicht REQUIRED CONFIG)

include_directories(${Irrlicht_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${Irrlicht_LIBRARY})