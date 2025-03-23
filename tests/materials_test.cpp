#include <gtest/gtest.h>
#include "Materials/material.hpp"
#include "Shapes/sphere.hpp"
#include "Ray.hpp"
#include "Vector/vec3.hpp"
#include "interval.hpp"
#include <memory>

using std::make_shared;

// Test lambertian material
TEST(MaterialTest, LambertianScatter) {
    color albedo(0.8, 0.3, 0.3);
    lambertian mat(albedo);

    point3 origin(0.0, 0.0, 0.0);
    vec3 direction(0.0, 0.0, -1.0);
    ray r_in(origin, direction);

    hit_record rec;
    rec.p = point3(0.0, 0.0, -1.0);
    rec.normal = vec3(0.0, 0.0, 1.0);
    rec.t = 1.0;
    rec.front_face = true;

    color attenuation;
    ray scattered;

    EXPECT_TRUE(mat.scatter(r_in, rec, attenuation, scattered));
    EXPECT_EQ(attenuation, albedo);
}

// Test metal material
TEST(MaterialTest, MetalScatter) {
    color albedo(0.8, 0.8, 0.8);
    double fuzz = 0.3;
    metal mat(albedo, fuzz);

    point3 origin(0.0, 0.0, 0.0);
    vec3 direction(0.0, 0.0, -1.0);
    ray r_in(origin, direction);

    hit_record rec;
    rec.p = point3(0.0, 0.0, -1.0);
    rec.normal = vec3(0.0, 0.0, 1.0);
    rec.t = 1.0;
    rec.front_face = true;

    color attenuation;
    ray scattered;

    EXPECT_TRUE(mat.scatter(r_in, rec, attenuation, scattered));
    EXPECT_EQ(attenuation, albedo);
    EXPECT_GT(dot(scattered.direction(), rec.normal), 0);
}

// Test dielectric material
TEST(MaterialTest, DielectricScatter) {
    double refraction_index = 1.5;
    dielectric mat(refraction_index);

    point3 origin(0.0, 0.0, 0.0);
    vec3 direction(0.0, 0.0, -1.0);
    ray r_in(origin, direction);

    hit_record rec;
    rec.p = point3(0.0, 0.0, -1.0);
    rec.normal = vec3(0.0, 0.0, 1.0);
    rec.t = 1.0;
    rec.front_face = true;

    color attenuation;
    ray scattered;

    EXPECT_TRUE(mat.scatter(r_in, rec, attenuation, scattered));
    EXPECT_EQ(attenuation, color(1.0, 1.0, 1.0));
}

// Test dielectric material with internal reflection
TEST(MaterialTest, DielectricInternalReflection) {
    double refraction_index = 1.5;
    dielectric mat(refraction_index);

    point3 origin(0.0, 0.0, 0.0);
    vec3 direction(0.0, 0.0, 1.0);
    ray r_in(origin, direction);

    hit_record rec;
    rec.p = point3(0.0, 0.0, 1.0);
    rec.normal = vec3(0.0, 0.0, -1.0);
    rec.t = 1.0;
    rec.front_face = false;

    color attenuation;
    ray scattered;

    EXPECT_TRUE(mat.scatter(r_in, rec, attenuation, scattered));
    EXPECT_EQ(attenuation, color(1.0, 1.0, 1.0));
}