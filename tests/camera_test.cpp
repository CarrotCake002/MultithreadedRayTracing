#include <gtest/gtest.h>
#include "Render/camera.hpp"
#include "Shapes/sphere.hpp"
#include "Hittables/hittable_list.hpp"
#include "Ray.hpp"
#include "Vector/vec3.hpp"
#include "interval.hpp"
#include "Materials/material.hpp"
#include <memory>

using std::make_shared;

// Test constructor and initialization of member variables
TEST(CameraTest, ConstructorInitialization) {
    camera cam;
    EXPECT_EQ(cam.aspect_ratio, 1.0);
    EXPECT_EQ(cam.image_width, 100);
    EXPECT_EQ(cam.samples_per_pixel, 10);
    EXPECT_EQ(cam.max_depth, 10);
    EXPECT_EQ(cam.vfov, 90);
    EXPECT_EQ(cam.lookfrom, point3(0, 0, 0));
    EXPECT_EQ(cam.lookat, point3(0, 0, -1));
    EXPECT_EQ(cam.vup, vec3(0, 1, 0));
    EXPECT_EQ(cam.defocus_angle, 0);
    EXPECT_EQ(cam.focus_dist, 10);
}
