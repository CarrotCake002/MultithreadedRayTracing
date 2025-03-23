#include <gtest/gtest.h>
#include "Hittables/hittable_list.hpp"
#include "Shapes/sphere.hpp"
#include "Ray.hpp"
#include "Vector/vec3.hpp"
#include "interval.hpp"
#include <memory>

using std::make_shared;

// Test constructor and initialization of member variables
TEST(HittableListTest, ConstructorInitialization) {
    hittable_list list;
    EXPECT_TRUE(list.objects.empty());

    auto sphere_ptr = make_shared<sphere>(point3(0, 0, -1), 0.5, nullptr);
    hittable_list list_with_object(sphere_ptr);
    EXPECT_EQ(list_with_object.objects.size(), 1);
    EXPECT_EQ(list_with_object.objects[0], sphere_ptr);
}

// Test clear() function
TEST(HittableListTest, Clear) {
    hittable_list list;
    auto sphere_ptr = make_shared<sphere>(point3(0, 0, -1), 0.5, nullptr);
    list.add(sphere_ptr);
    EXPECT_EQ(list.objects.size(), 1);

    list.clear();
    EXPECT_TRUE(list.objects.empty());
}

// Test add(shared_ptr<hittable> object) function
TEST(HittableListTest, Add) {
    hittable_list list;
    auto sphere_ptr = make_shared<sphere>(point3(0, 0, -1), 0.5, nullptr);
    list.add(sphere_ptr);
    EXPECT_EQ(list.objects.size(), 1);
    EXPECT_EQ(list.objects[0], sphere_ptr);

    auto another_sphere_ptr = make_shared<sphere>(point3(1, 0, -1), 0.5, nullptr);
    list.add(another_sphere_ptr);
    EXPECT_EQ(list.objects.size(), 2);
    EXPECT_EQ(list.objects[1], another_sphere_ptr);
}

// Test hit(const ray& r, interval ray_t, hit_record& rec) function
TEST(HittableListTest, HitFunction) {
    hittable_list list;
    auto sphere_ptr = make_shared<sphere>(point3(0, 0, -1), 0.5, nullptr);
    list.add(sphere_ptr);

    ray r(point3(0, 0, 0), vec3(0, 0, -1));
    interval ray_t(0.0, infinity);
    hit_record rec;

    EXPECT_TRUE(list.hit(r, ray_t, rec));
    EXPECT_NEAR(rec.t, 0.5, 1e-6);
    EXPECT_EQ(rec.p, point3(0, 0, -0.5));
    EXPECT_EQ(rec.normal, vec3(0, 0, 1));
    EXPECT_TRUE(rec.front_face);

    // Test with no hit
    ray r_miss(point3(0, 0, 0), vec3(0, 1, 0));
    EXPECT_FALSE(list.hit(r_miss, ray_t, rec));
}