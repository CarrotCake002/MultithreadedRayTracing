cmake_minimum_required(VERSION 3.10)
project(VectorTests)

set(CMAKE_CXX_STANDARD 11)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(vec3_test vec3_test.cpp)

find_package(GTest REQUIRED)
target_link_libraries(vec3_test GTest::GTest GTest::Main)

target_link_libraries(vec3_test gtest_main)
add_test(NAME vec3_test COMMAND vec3_test)