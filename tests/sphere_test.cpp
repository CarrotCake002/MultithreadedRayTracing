#include <gtest/gtest.h>
#include "Shapes/sphere.hpp"
#include "Ray.hpp"
#include "Vector/vec3.hpp"
#include "interval.hpp"
#include "Materials/material.hpp"
#include <memory>

using std::make_shared;

// Test when the ray hits the sphere
TEST(SphereTest, RayHitsSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    sphere s(center, radius, material);
    ray r(point3(0.0, 0.0, 0.0), vec3(0.0, 0.0, -1.0));
    interval ray_t(0.0, infinity);
    hit_record rec;

    EXPECT_TRUE(s.hit(r, ray_t, rec));
    EXPECT_NEAR(rec.t, 4.0, 1e-6);
    EXPECT_EQ(rec.p, point3(0.0, 0.0, -4.0));
    EXPECT_EQ(rec.mat, material);
}

// Test when the ray misses the sphere
TEST(SphereTest, RayMissesSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    sphere s(center, radius, material);
    ray r(point3(0.0, 2.0, 0.0), vec3(0.0, 0.0, -1.0));
    interval ray_t(0.0, infinity);
    hit_record rec;

    EXPECT_FALSE(s.hit(r, ray_t, rec));
}

// Test when the ray is tangent to the sphere
TEST(SphereTest, RayTangentToSphere) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    sphere s(center, radius, material);
    ray r(point3(1.0, 0.0, 0.0), vec3(0.0, 0.0, -1.0));
    interval ray_t(0.0, infinity);
    hit_record rec;

    EXPECT_TRUE(s.hit(r, ray_t, rec));
    EXPECT_NEAR(rec.t, 5.0, 1e-6);
    EXPECT_EQ(rec.p, point3(1.0, 0.0, -5.0));
    EXPECT_EQ(rec.mat, material);
}

// Test when the ray starts on the sphere’s surface and moves away
TEST(SphereTest, RayStartsOnSurfaceMovingAway) {
    point3 center(0.0, 0.0, -5.0);
    double radius = 1.0;
    auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    sphere s(center, radius, material);
    ray r(point3(0.0, 0.0, -4.0), vec3(0.0, 0.0, 1.0));
    interval ray_t(0.0, infinity);
    hit_record rec;

    EXPECT_FALSE(s.hit(r, ray_t, rec));
}
