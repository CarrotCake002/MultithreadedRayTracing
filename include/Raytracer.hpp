#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

#include "Vector/vec3.hpp"
#include "Vector/color.hpp"
#include "Ray.hpp"

// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Raytracing Functions
double hit_sphere(const point3& center, double radius, const ray& r);
color ray_color(const ray& r);

#endif // RAYTRACER_HPP