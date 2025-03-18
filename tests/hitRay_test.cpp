#include <gtest/gtest.h>
#include "../include/Ray.hpp"
#include "../include/Raytracer.hpp"
#include "../include/Vector/vec3.hpp"

// Test when the ray directly hits the sphere
TEST(HitSphereTest, RayHitsSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(0.0, 0.0, 0.0), vec3(0.0, 0.0, -1.0));

    EXPECT_TRUE(hit_sphere(center, radius, r));
}

// Test when the ray completely misses the sphere
TEST(HitSphereTest, RayMissesSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(0.0, 2.0, 0.0), vec3(0.0, 0.0, -1.0));

    EXPECT_FALSE(hit_sphere(center, radius, r));
}

// Test when the ray is tangent to the sphere
TEST(HitSphereTest, RayTangentToSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(1.0, 0.0, 0.0), vec3(0.0, 0.0, -1.0));

    EXPECT_TRUE(hit_sphere(center, radius, r));
}

// Test when the ray starts inside the sphere
TEST(HitSphereTest, RayStartsInsideSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 3.0;
    ray r(point3(0.0, 0.0, -5.0), vec3(0.0, 0.0, -1.0));

    EXPECT_TRUE(hit_sphere(center, radius, r));
}

// Test when the ray starts on the sphere’s surface and moves away
TEST(HitSphereTest, RayStartsOnSurfaceMovingAway) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    ray r(point3(0.0, 0.0, -4.0), vec3(0.0, 0.0, 1.0));

    EXPECT_FALSE(hit_sphere(center, radius, r));
}
