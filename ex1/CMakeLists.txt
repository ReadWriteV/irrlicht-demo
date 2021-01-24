cmake_minimum_required(VERSION 3.5)

# Set the project name
project(ex1)

# Set Irrlicht_DIR to find irrlicht
set(Irrlicht_DIR D:/SDK/irrlicht-1.8.4)

# find IRRLICHT
find_package(Irrlicht REQUIRED CONFIG)

include_directories(${Irrlicht_INCLUDE_DIR})

add_executable(ex1 main.cpp)

target_link_libraries(ex1 ${Irrlicht_LIBRARY})
