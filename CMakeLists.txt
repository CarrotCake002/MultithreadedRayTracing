cmake_minimum_required(VERSION 3.10)
project(raytracer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Find all .cpp files in src/ and subdirectories
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Find all subdirectories in the include directory
file(GLOB INCLUDE_DIRS RELATIVE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/*)

# Add the include directory and all its subdirectories
foreach(dir ${INCLUDE_DIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/include/${dir})
        include_directories(${CMAKE_SOURCE_DIR}/include/${dir})
    endif()
endforeach()

# Define the executable
add_executable(raytracer ${SRC_FILES})

# Ensure the compiler searches the include directory
target_include_directories(raytracer PRIVATE ${CMAKE_SOURCE_DIR}/include)
