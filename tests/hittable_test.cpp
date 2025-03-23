#include <gtest/gtest.h>
#include "Hittables/hittable.hpp"
#include "Ray.hpp"
#include "Vector/vec3.hpp"
#include <memory>

using std::make_shared;

// Test set_face_normal function
TEST(HitRecordTest, SetFaceNormal) {
    hit_record rec;
    ray r(point3(0, 0, 0), vec3(0, 0, -1));
    vec3 outward_normal(0, 0, 1);

    rec.set_face_normal(r, outward_normal);
    EXPECT_TRUE(rec.front_face);
    EXPECT_EQ(rec.normal, outward_normal);

    r = ray(point3(0, 0, 0), vec3(0, 0, 1));
    rec.set_face_normal(r, outward_normal);
    EXPECT_FALSE(rec.front_face);
    EXPECT_EQ(rec.normal, -outward_normal);
}

// Mock hittable class for testing
class mock_hittable : public hittable {
  public:
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        rec.t = 1.0;
        rec.p = r.at(rec.t);
        rec.normal = vec3(0, 0, 1);
        rec.mat = nullptr;
        rec.set_face_normal(r, rec.normal);
        return true;
    }
};

// Test hittable hit function
TEST(HittableTest, HitFunction) {
    mock_hittable h;
    ray r(point3(0, 0, 0), vec3(0, 0, -1));
    interval ray_t(0.0, infinity);
    hit_record rec;

    EXPECT_TRUE(h.hit(r, ray_t, rec));
    EXPECT_NEAR(rec.t, 1.0, 1e-6);
    EXPECT_EQ(rec.p, point3(0, 0, -1));
    EXPECT_EQ(rec.normal, vec3(0, 0, 1));
    EXPECT_TRUE(rec.front_face);
}