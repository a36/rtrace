#ifndef _VEC3_H
#define _VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3
{
public:
	vec3() : v{ 0,0,0 } {}
	vec3(double x, double y, double z) : v{ x, y, z } {}

	double x() const { return v[0]; }
	double y() const { return v[1]; }
	double z() const { return v[2]; }

// Point..?
public:
	double v[3];
};

#endif