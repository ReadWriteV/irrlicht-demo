cmake_minimum_required(VERSION 3.5)

# Set Irrlicht root path
set(IRRLICHT_ROOT_PATH D:/SDK/irrlicht-1.8.4)

# Set the project name
project(ex7)

# Set Irrlicht include path
include_directories(${IRRLICHT_ROOT_PATH}/include)

# Set Irrlicht library path
link_directories(${IRRLICHT_ROOT_PATH}/lib/x64)

# Add an executable
add_executable(ex7 main.cpp)

# Link library
target_link_libraries(ex7 Irrlicht)