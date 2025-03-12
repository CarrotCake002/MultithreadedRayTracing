cmake_minimum_required(VERSION 3.10)
project(raytracer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Find all .cpp files in src/ and subdirectories
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Add the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/Vector)

# Define the executable
add_executable(raytracer ${SRC_FILES})

# Ensure the compiler searches the include directory
target_include_directories(raytracer PRIVATE ${CMAKE_SOURCE_DIR}/include)
