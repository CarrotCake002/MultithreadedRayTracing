#include <gtest/gtest.h>
#include "interval.hpp"

// Test default constructor
TEST(IntervalTest, DefaultConstructor) {
    interval i;
    EXPECT_EQ(i.min, +infinity);
    EXPECT_EQ(i.max, -infinity);
}

// Test parameterized constructor
TEST(IntervalTest, ParameterizedConstructor) {
    double min = 1.0;
    double max = 2.0;
    interval i(min, max);
    EXPECT_EQ(i.min, min);
    EXPECT_EQ(i.max, max);
}

// Test size() method
TEST(IntervalTest, Size) {
    interval i(1.0, 3.0);
    EXPECT_EQ(i.size(), 2.0);
}

// Test size() method with negative interval
TEST(IntervalTest, SizeNegative) {
    interval i(-3.0, -1.0);
    EXPECT_EQ(i.size(), 2.0);
}

// Test size() method with zero interval
TEST(IntervalTest, SizeZero) {
    interval i(2.0, 2.0);
    EXPECT_EQ(i.size(), 0.0);
}

// Test contains() method
TEST(IntervalTest, Contains) {
    interval i(1.0, 3.0);
    EXPECT_TRUE(i.contains(2.0));
    EXPECT_TRUE(i.contains(1.0));
    EXPECT_TRUE(i.contains(3.0));
    EXPECT_FALSE(i.contains(0.0));
    EXPECT_FALSE(i.contains(4.0));
}

// Test contains() method with negative values
TEST(IntervalTest, ContainsNegative) {
    interval i(-3.0, -1.0);
    EXPECT_TRUE(i.contains(-2.0));
    EXPECT_TRUE(i.contains(-3.0));
    EXPECT_TRUE(i.contains(-1.0));
    EXPECT_FALSE(i.contains(-4.0));
    EXPECT_FALSE(i.contains(0.0));
}

// Test surrounds() method
TEST(IntervalTest, Surrounds) {
    interval i(1.0, 3.0);
    EXPECT_TRUE(i.surrounds(2.0));
    EXPECT_FALSE(i.surrounds(1.0));
    EXPECT_FALSE(i.surrounds(3.0));
    EXPECT_FALSE(i.surrounds(0.0));
    EXPECT_FALSE(i.surrounds(4.0));
}

// Test surrounds() method with negative values
TEST(IntervalTest, SurroundsNegative) {
    interval i(-3.0, -1.0);
    EXPECT_TRUE(i.surrounds(-2.0));
    EXPECT_FALSE(i.surrounds(-3.0));
    EXPECT_FALSE(i.surrounds(-1.0));
    EXPECT_FALSE(i.surrounds(-4.0));
    EXPECT_FALSE(i.surrounds(0.0));
}

// Test clamp() method
TEST(IntervalTest, Clamp) {
    interval i(1.0, 3.0);
    EXPECT_EQ(i.clamp(2.0), 2.0);
    EXPECT_EQ(i.clamp(1.0), 1.0);
    EXPECT_EQ(i.clamp(3.0), 3.0);
    EXPECT_EQ(i.clamp(0.0), 1.0);
    EXPECT_EQ(i.clamp(4.0), 3.0);
}

// Test clamp() method with negative values
TEST(IntervalTest, ClampNegative) {
    interval i(-3.0, -1.0);
    EXPECT_EQ(i.clamp(-2.0), -2.0);
    EXPECT_EQ(i.clamp(-3.0), -3.0);
    EXPECT_EQ(i.clamp(-1.0), -1.0);
    EXPECT_EQ(i.clamp(-4.0), -3.0);
    EXPECT_EQ(i.clamp(0.0), -1.0);
}

// Test clamp() method with zero interval
TEST(IntervalTest, ClampZeroInterval) {
    interval i(2.0, 2.0);
    EXPECT_EQ(i.clamp(1.0), 2.0);
    EXPECT_EQ(i.clamp(2.0), 2.0);
    EXPECT_EQ(i.clamp(3.0), 2.0);
}

// Test empty interval
TEST(IntervalTest, EmptyInterval) {
    EXPECT_EQ(interval::empty.min, +infinity);
    EXPECT_EQ(interval::empty.max, -infinity);
    EXPECT_EQ(interval::empty.size(), -infinity);
    EXPECT_FALSE(interval::empty.contains(0.0));
    EXPECT_FALSE(interval::empty.surrounds(0.0));
    EXPECT_EQ(interval::empty.clamp(0.0), +infinity);
}

// Test universe interval
TEST(IntervalTest, UniverseInterval) {
    EXPECT_EQ(interval::universe.min, -infinity);
    EXPECT_EQ(interval::universe.max, +infinity);
    EXPECT_EQ(interval::universe.size(), +infinity);
    EXPECT_TRUE(interval::universe.contains(0.0));
    EXPECT_TRUE(interval::universe.surrounds(0.0));
    EXPECT_EQ(interval::universe.clamp(0.0), 0.0);
}