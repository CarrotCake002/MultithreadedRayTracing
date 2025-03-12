#ifndef COLOR_H
#define COLOR_H

#include "vec3.hpp"

using color = vec3;

void write_color(std::ostream &out, const color &pixel_color);

#endif