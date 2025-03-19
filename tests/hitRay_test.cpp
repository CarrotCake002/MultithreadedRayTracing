#include <gtest/gtest.h>
#include "../include/Ray.hpp"
#include "../include/Raytracer.hpp"
#include "../include/Vector/vec3.hpp"

// Test when the ray directly hits the sphere
TEST(HitSphereTest, RayHitsSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(0.0, 0.0, 0.0), vec3(0.0, 0.0, -1.0));

    double t = hit_sphere(center, radius, r);
    EXPECT_GT(t, 0.0);
    EXPECT_NEAR(t, 4.0, 1e-6); // The distance should be 4.0
}

// Test when the ray completely misses the sphere
TEST(HitSphereTest, RayMissesSphere) {  
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(0.0, 2.0, 0.0), vec3(0.0, 0.0, -1.0));

    double t = hit_sphere(center, radius, r);
    EXPECT_EQ(t, -1.0);
}

// Test when the ray is tangent to the sphere
TEST(HitSphereTest, RayTangentToSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(1.0, 0.0, 0.0), vec3(0.0, 0.0, -1.0));

    double t = hit_sphere(center, radius, r);
    EXPECT_GT(t, 0.0);
    EXPECT_NEAR(t, 5.0, 1e-6); // The distance should be 5.0
}

// Test when the ray is parallel to the sphere but does not intersect
TEST(HitSphereTest, RayParallelToSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(0.0, 2.0, 0.0), vec3(1.0, 0.0, 0.0));

    double t = hit_sphere(center, radius, r);
    EXPECT_EQ(t, -1.0);
}
