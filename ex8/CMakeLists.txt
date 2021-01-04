cmake_minimum_required(VERSION 3.5)

# Set irrKlang root path
set(IRRKLANG_ROOT_PATH D:/SDK/irrKlang-1.6.0)

# Set the project name
project(ex8)

# Set Irrlicht include path
include_directories(${IRRKLANG_ROOT_PATH}/include)

# Set Irrlicht library path
link_directories(${IRRKLANG_ROOT_PATH}/lib/x64)

# Add an executable
add_executable(ex8 main.cpp)

# Link library
target_link_libraries(ex8 irrKlang)