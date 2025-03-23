#include <gtest/gtest.h>
#include "Vector/vec3.hpp"
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

// Test for operator<<
TEST(Vec3Test, OperatorOutput) {
    vec3 v(1.0, 2.0, 3.0);
    std::stringstream ss;
    ss << v;
    EXPECT_EQ(ss.str(), "1 2 3");
}

// Test for operator+
TEST(Vec3Test, OperatorAdd) {
    vec3 u(1.0, 2.0, 3.0);
    vec3 v(4.0, 5.0, 6.0);
    vec3 result = u + v;
    EXPECT_EQ(result.x(), 5.0);
    EXPECT_EQ(result.y(), 7.0);
    EXPECT_EQ(result.z(), 9.0);
}

// Test for operator- (vec3 - vec3)
TEST(Vec3Test, OperatorSubtract) {
    vec3 u(4.0, 5.0, 6.0);
    vec3 v(1.0, 2.0, 3.0);
    vec3 result = u - v;
    EXPECT_EQ(result.x(), 3.0);
    EXPECT_EQ(result.y(), 3.0);
    EXPECT_EQ(result.z(), 3.0);
}

// Test for operator- (vec3 - vec3) with negative result
TEST(Vec3Test, OperatorSubtractNegative) {
    vec3 u(1.0, 2.0, 3.0);
    vec3 v(4.0, 5.0, 6.0);
    vec3 result = u - v;
    EXPECT_EQ(result.x(), -3.0);
    EXPECT_EQ(result.y(), -3.0);
    EXPECT_EQ(result.z(), -3.0);
}

// Test for operator* (vec3 * vec3)
TEST(Vec3Test, OperatorMultiplyVec3) {
    vec3 u(1.0, 2.0, 3.0);
    vec3 v(4.0, 5.0, 6.0);
    vec3 result = u * v;
    EXPECT_EQ(result.x(), 4.0);
    EXPECT_EQ(result.y(), 10.0);
    EXPECT_EQ(result.z(), 18.0);
}

// Test for operator* (double * vec3)
TEST(Vec3Test, OperatorMultiplyDoubleVec3) {
    vec3 v(1.0, 2.0, 3.0);
    double t = 2.0;
    vec3 result = t * v;
    EXPECT_EQ(result.x(), 2.0);
    EXPECT_EQ(result.y(), 4.0);
    EXPECT_EQ(result.z(), 6.0);
}

// Test for operator* (vec3 * double)
TEST(Vec3Test, OperatorMultiplyVec3Double) {
    vec3 v(1.0, 2.0, 3.0);
    double t = 2.0;
    vec3 result = v * t;
    EXPECT_EQ(result.x(), 2.0);
    EXPECT_EQ(result.y(), 4.0);
    EXPECT_EQ(result.z(), 6.0);
}

// Test for operator/ (vec3 / double)
TEST(Vec3Test, OperatorDivide) {
    vec3 v(2.0, 4.0, 6.0);
    double t = 2.0;
    vec3 result = v / t;
    EXPECT_EQ(result.x(), 1.0);
    EXPECT_EQ(result.y(), 2.0);
    EXPECT_EQ(result.z(), 3.0);
}

// Test for operator/ (vec3 / double) with zero divisor
TEST(Vec3Test, OperatorDivideByZero) {
    vec3 v(2.0, 4.0, 6.0);
    double t = 0.0;
    EXPECT_THROW(v / t, std::runtime_error);
}

// Test for dot product
TEST(Vec3Test, DotProduct) {
    vec3 u(1.0, 2.0, 3.0);
    vec3 v(4.0, 5.0, 6.0);
    double result = dot(u, v);
    EXPECT_EQ(result, 32.0);
}

// Test for dot product with orthogonal vectors
TEST(Vec3Test, DotProductOrthogonal) {
    vec3 u(1.0, 0.0, 0.0);
    vec3 v(0.0, 1.0, 0.0);
    double result = dot(u, v);
    EXPECT_EQ(result, 0.0);
}

// Test for cross product
TEST(Vec3Test, CrossProduct) {
    vec3 u(1.0, 2.0, 3.0);
    vec3 v(4.0, 5.0, 6.0);
    vec3 result = cross(u, v);
    EXPECT_EQ(result.x(), -3.0);
    EXPECT_EQ(result.y(), 6.0);
    EXPECT_EQ(result.z(), -3.0);
}

// Test for cross product with parallel vectors
TEST(Vec3Test, CrossProductParallel) {
    vec3 u(1.0, 2.0, 3.0);
    vec3 v(2.0, 4.0, 6.0);
    vec3 result = cross(u, v);
    EXPECT_EQ(result.x(), 0.0);
    EXPECT_EQ(result.y(), 0.0);
    EXPECT_EQ(result.z(), 0.0);
}

// Test for unit vector
TEST(Vec3Test, UnitVector) {
    vec3 v(3.0, 4.0, 0.0);
    vec3 result = unit_vector(v);
    EXPECT_NEAR(result.x(), 0.6, 1e-6);
    EXPECT_NEAR(result.y(), 0.8, 1e-6);
    EXPECT_NEAR(result.z(), 0.0, 1e-6);
}

// Test for unit vector of zero vector
TEST(Vec3Test, UnitVectorZero) {
    vec3 v(0.0, 0.0, 0.0);
    EXPECT_THROW(unit_vector(v), std::runtime_error);
}

// Test for random_unit_vector
TEST(Vec3Test, RandomUnitVector) {
    for (int i = 0; i < 1000; ++i) {
        vec3 v = random_unit_vector();
        double length = v.length();
        EXPECT_NEAR(length, 1.0, 1e-6);
    }
}

// Test for random_on_hemisphere
TEST(Vec3Test, RandomOnHemisphere) {
    vec3 normal(0.0, 0.0, 1.0);
    for (int i = 0; i < 1000; ++i) {
        vec3 v = random_on_hemisphere(normal);
        double length = v.length();
        EXPECT_NEAR(length, 1.0, 1e-6);
        EXPECT_GT(dot(v, normal), 0.0);
    }
}

// Test for reflect
TEST(Vec3Test, Reflect) {
    vec3 v(1.0, -1.0, 0.0);
    vec3 n(0.0, 1.0, 0.0);
    vec3 result = reflect(v, n);
    EXPECT_EQ(result.x(), 1.0);
    EXPECT_EQ(result.y(), 1.0);
    EXPECT_EQ(result.z(), 0.0);
}

// Test for reflect with different normal
TEST(Vec3Test, ReflectDifferentNormal) {
    vec3 v(1.0, 1.0, 0.0);
    vec3 n(1.0, 0.0, 0.0);
    vec3 result = reflect(v, n);
    EXPECT_EQ(result.x(), -1.0);
    EXPECT_EQ(result.y(), 1.0);
    EXPECT_EQ(result.z(), 0.0);
}

// Test for refract
TEST(Vec3Test, Refract) {
    vec3 uv(1.0, -1.0, 0.0);
    vec3 n(0.0, 1.0, 0.0);
    double etai_over_etat = 0.5;
    vec3 result = refract(uv, n, etai_over_etat);
    EXPECT_NEAR(result.x(), 0.5, 1e-6);
    EXPECT_NEAR(result.y(), -0.866025, 1e-6);
    EXPECT_NEAR(result.z(), 0.0, 1e-6);
}

// Test for random_in_unit_disk
TEST(Vec3Test, RandomInUnitDisk) {
    for (int i = 0; i < 1000; ++i) {
        vec3 v = random_in_unit_disk();
        EXPECT_LE(v.length_squared(), 1.0);
        EXPECT_EQ(v.z(), 0.0);
    }
}

// Test for random_in_unit_disk with different ranges
TEST(Vec3Test, RandomInUnitDiskDifferentRanges) {
    for (int i = 0; i < 1000; ++i) {
        vec3 v = random_in_unit_disk();
        EXPECT_LE(v.length_squared(), 1.0);
        EXPECT_EQ(v.z(), 0.0);
    }
}
