cmake_minimum_required(VERSION 3.5)

# Set the project name
project(ex1)

# Set Irrlicht_DIR and CMAKE_MODULE_PATH to find irrlicht
set(Irrlicht_DIR D:/SDK/irrlicht-1.8.4)
set(CMAKE_MODULE_PATH D:/SDK/irrlicht-1.8.4/cmake)

# find IRRLICHT
find_package(Irrlicht QUIET REQUIRED)

if(Irrlicht_FOUND)
    add_executable(ex1 main.cpp)
    include_directories(${Irrlicht_INCLUDE_DIR})
    target_link_libraries(ex1 ${Irrlicht_LIBRARY})
else(Irrlicht_FOUND)
    message(FATAL_ERROR "Irrlicht library not found")
endif(Irrlicht_FOUND)