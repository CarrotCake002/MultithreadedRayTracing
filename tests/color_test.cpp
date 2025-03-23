#include <gtest/gtest.h>
#include "../include/Vector/color.hpp"
#include <sstream>

// Test for linear_to_gamma function
TEST(ColorTest, LinearToGamma) {
    EXPECT_NEAR(linear_to_gamma(0.0), 0.0, 1e-6);
    EXPECT_NEAR(linear_to_gamma(0.25), 0.5, 1e-6);
    EXPECT_NEAR(linear_to_gamma(1.0), 1.0, 1e-6);
    EXPECT_NEAR(linear_to_gamma(0.5), std::sqrt(0.5), 1e-6);
    EXPECT_NEAR(linear_to_gamma(0.75), std::sqrt(0.75), 1e-6);
    EXPECT_NEAR(linear_to_gamma(-0.5), 0.0, 1e-6); // Negative value should return 0
}

// Test for write_color function
TEST(ColorTest, WriteColor) {
    std::stringstream ss;
    color pixel_color(0.25, 0.5, 0.75);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "128 181 221\n"); // Corrected expected values after gamma correction and clamping

    ss.str("");
    ss.clear();
    pixel_color = color(1.0, 1.0, 1.0);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "255 255 255\n");

    ss.str("");
    ss.clear();
    pixel_color = color(0.0, 0.0, 0.0);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "0 0 0\n");

    ss.str("");
    ss.clear();
    pixel_color = color(-0.5, 0.5, 1.5);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "0 181 255\n"); // Negative value should be clamped to 0, and value > 1 should be clamped to 1

    ss.str("");
    ss.clear();
    pixel_color = color(0.999, 0.999, 0.999);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "255 255 255\n"); // Values close to 1 should be clamped to 255
}

// Test for write_color function with edge cases
TEST(ColorTest, WriteColorEdgeCases) {
    std::stringstream ss;
    color pixel_color(0.001, 0.001, 0.001);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "8 8 8\n"); // Corrected expected values after gamma correction and clamping

    ss.str("");
    ss.clear();
    pixel_color = color(0.5, 0.5, 0.5);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "181 181 181\n"); // Mid-range values should be correctly gamma corrected and clamped

    ss.str("");
    ss.clear();
    pixel_color = color(0.75, 0.75, 0.75);
    write_color(ss, pixel_color);
    EXPECT_EQ(ss.str(), "221 221 221\n"); // Corrected expected values after gamma correction and clamping
}