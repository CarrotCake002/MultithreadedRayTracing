#include <gtest/gtest.h>
#include "Raytracer.hpp"
#include <cmath>
#include <limits>

// Test for degrees_to_radians
TEST(RaytracerTest, DegreesToRadians) {
    EXPECT_NEAR(degrees_to_radians(0.0), 0.0, 1e-6);
    EXPECT_NEAR(degrees_to_radians(90.0), pi / 2, 1e-6);
    EXPECT_NEAR(degrees_to_radians(180.0), pi, 1e-6);
    EXPECT_NEAR(degrees_to_radians(270.0), 3 * pi / 2, 1e-6);
    EXPECT_NEAR(degrees_to_radians(360.0), 2 * pi, 1e-6);
    EXPECT_NEAR(degrees_to_radians(-90.0), -pi / 2, 1e-6);
    EXPECT_NEAR(degrees_to_radians(45.0), pi / 4, 1e-6);
}

// Test for random_double() in [0, 1)
TEST(RaytracerTest, RandomDouble) {
    for (int i = 0; i < 1000; ++i) {
        double value = random_double();
        EXPECT_GE(value, 0.0);
        EXPECT_LT(value, 1.0);
    }
}

// Test for random_double(double min, double max) with positive range
TEST(RaytracerTest, RandomDoublePositiveRange) {
    double min = 1.0;
    double max = 2.0;
    for (int i = 0; i < 1000; ++i) {
        double value = random_double(min, max);
        EXPECT_GE(value, min);
        EXPECT_LT(value, max);
    }
}

// Test for random_double(double min, double max) with negative range
TEST(RaytracerTest, RandomDoubleNegativeRange) {
    double min = -2.0;
    double max = -1.0;
    for (int i = 0; i < 1000; ++i) {
        double value = random_double(min, max);
        EXPECT_GE(value, min);
        EXPECT_LT(value, max);
    }
}

// Test for random_double(double min, double max) with mixed range
TEST(RaytracerTest, RandomDoubleMixedRange) {
    double min = -1.0;
    double max = 1.0;
    for (int i = 0; i < 1000; ++i) {
        double value = random_double(min, max);
        EXPECT_GE(value, min);
        EXPECT_LT(value, max);
    }
}

// Test for random_double(double min, double max) with zero range
TEST(RaytracerTest, RandomDoubleZeroRange) {
    double min = 0.0;
    double max = 0.0;
    for (int i = 0; i < 1000; ++i) {
        double value = random_double(min, max);
        EXPECT_EQ(value, min);
    }
}

// Test for random_double(double min, double max) with large range
TEST(RaytracerTest, RandomDoubleLargeRange) {
    double min = -1e6;
    double max = 1e6;
    for (int i = 0; i < 1000; ++i) {
        double value = random_double(min, max);
        EXPECT_GE(value, min);
        EXPECT_LT(value, max);
    }
}