cmake_minimum_required(VERSION 3.10)
project(VectorTests)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC_FILES "../src/*.cpp")
file(GLOB_RECURSE TEST_FILES "*.cpp")

list(FILTER SRC_FILES EXCLUDE REGEX ".*main.cpp$")
list(FILTER SRC_FILES EXCLUDE REGEX ".*/build/.*")
list(FILTER TEST_FILES EXCLUDE REGEX ".*/build/.*")

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/../include)

add_executable(testing ${SRC_FILES} ${TEST_FILES})
target_link_libraries(testing gtest gtest_main)

find_package(GTest REQUIRED)
target_link_libraries(testing GTest::GTest GTest::Main)

target_link_libraries(testing gtest_main)
add_test(NAME testing COMMAND testing)