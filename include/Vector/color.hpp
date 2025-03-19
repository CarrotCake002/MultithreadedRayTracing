#ifndef COLOR_HPP
#define COLOR_HPP

#include "Vector/vec3.hpp"

using color = vec3;

void write_color(std::ostream &out, const color &pixel_color);

#endif