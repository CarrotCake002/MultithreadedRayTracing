#include <gtest/gtest.h>
#include "../include/Vector/vec3.hpp"
#include <cmath>

// Test operator- (Unary Negation)
TEST(Vec3Test, UnaryNegation) {
    vec3 v(1.0f, -2.0f, 3.0f);
    vec3 result = -v;
    
    EXPECT_FLOAT_EQ(result.e[0], -1.0f);
    EXPECT_FLOAT_EQ(result.e[1], 2.0f);
    EXPECT_FLOAT_EQ(result.e[2], -3.0f);
}

// Test operator[] (const)
TEST(Vec3Test, ConstIndexOperator) {
    vec3 v(1.0f, 2.0f, 3.0f);
    
    EXPECT_FLOAT_EQ(v[0], 1.0f);
    EXPECT_FLOAT_EQ(v[1], 2.0f);
    EXPECT_FLOAT_EQ(v[2], 3.0f);
}

// Test operator[] (non-const)
TEST(Vec3Test, NonConstIndexOperator) {
    vec3 v(1.0f, 2.0f, 3.0f);
    v[0] = 4.0f;
    v[1] = 5.0f;
    v[2] = 6.0f;
    
    EXPECT_FLOAT_EQ(v[0], 4.0f);
    EXPECT_FLOAT_EQ(v[1], 5.0f);
    EXPECT_FLOAT_EQ(v[2], 6.0f);
}

// Test operator+= (Addition Assignment)
TEST(Vec3Test, AdditionAssignment) {
    vec3 a(1.0f, 2.0f, 3.0f);
    vec3 b(4.0f, 5.0f, 6.0f);

    a += b;

    EXPECT_FLOAT_EQ(a.e[0], 5.0f);
    EXPECT_FLOAT_EQ(a.e[1], 7.0f);
    EXPECT_FLOAT_EQ(a.e[2], 9.0f);
}

// Test operator*= (Scalar Multiplication Assignment)
TEST(Vec3Test, ScalarMultiplicationAssignment) {
    vec3 v(1.0f, 2.0f, 3.0f);
    v *= 2.0f;
    
    EXPECT_FLOAT_EQ(v.e[0], 2.0f);
    EXPECT_FLOAT_EQ(v.e[1], 4.0f);
    EXPECT_FLOAT_EQ(v.e[2], 6.0f);
}

// Test operator/= (Scalar Division Assignment)
TEST(Vec3Test, ScalarDivisionAssignment) {
    vec3 v(2.0f, 4.0f, 6.0f);
    v /= 2.0f;
    
    EXPECT_FLOAT_EQ(v.e[0], 1.0f);
    EXPECT_FLOAT_EQ(v.e[1], 2.0f);
    EXPECT_FLOAT_EQ(v.e[2], 3.0f);
}

// Test length (Euclidean length)
TEST(Vec3Test, Length) {
    vec3 v(3.0f, 4.0f, 0.0f);
    double result = v.length();
    
    EXPECT_FLOAT_EQ(result, 5.0f);
}

// Test length_squared (Squared length)
TEST(Vec3Test, LengthSquared) {
    vec3 v(3.0f, 4.0f, 0.0f);
    double result = v.length_squared();
    
    EXPECT_FLOAT_EQ(result, 25.0f);
}
