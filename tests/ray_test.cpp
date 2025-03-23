#include <gtest/gtest.h>
#include "Ray.hpp"
#include "Vector/vec3.hpp"

// Test default constructor
TEST(RayTest, DefaultConstructor) {
    ray r;
    EXPECT_EQ(r.origin(), point3());
    EXPECT_EQ(r.direction(), vec3());
}

// Test parameterized constructor
TEST(RayTest, ParameterizedConstructor) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    EXPECT_EQ(r.origin(), origin);
    EXPECT_EQ(r.direction(), direction);
}

// Test origin() method
TEST(RayTest, Origin) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    EXPECT_EQ(r.origin(), origin);
}

// Test direction() method
TEST(RayTest, Direction) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    EXPECT_EQ(r.direction(), direction);
}

// Test at() method
TEST(RayTest, At) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    double t = 2.0;
    point3 expected_point = origin + t * direction;
    EXPECT_EQ(r.at(t), expected_point);
}

// Test at() method with t = 0
TEST(RayTest, AtZero) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    double t = 0.0;
    EXPECT_EQ(r.at(t), origin);
}

// Test at() method with negative t
TEST(RayTest, AtNegative) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    double t = -1.0;
    point3 expected_point = origin + t * direction;
    EXPECT_EQ(r.at(t), expected_point);
}

// Test at() method with large t
TEST(RayTest, AtLargeT) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    double t = 1e6;
    point3 expected_point = origin + t * direction;
    EXPECT_EQ(r.at(t), expected_point);
}

// Test at() method with small t
TEST(RayTest, AtSmallT) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    double t = 1e-6;
    point3 expected_point = origin + t * direction;
    EXPECT_EQ(r.at(t), expected_point);
}

// Test at() method with t = 1
TEST(RayTest, AtOne) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    double t = 1.0;
    point3 expected_point = origin + t * direction;
    EXPECT_EQ(r.at(t), expected_point);
}

// Test at() method with t = -1
TEST(RayTest, AtNegativeOne) {
    point3 origin(1.0, 2.0, 3.0);
    vec3 direction(4.0, 5.0, 6.0);
    ray r(origin, direction);
    double t = -1.0;
    point3 expected_point = origin + t * direction;
    EXPECT_EQ(r.at(t), expected_point);
}