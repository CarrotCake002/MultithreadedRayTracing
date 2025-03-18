#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <iostream>

#include "Vector/vec3.hpp"
#include "Vector/color.hpp"
#include "Ray.hpp"

bool hit_sphere(const point3& center, double radius, const ray& r);
color ray_color(const ray& r);

#endif // RAYTRACER_HPP