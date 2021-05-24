#ifndef _VEC3_H
#define _VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:
    vec3()
        : v { 0, 0, 0 }
    {
    }
    vec3(double x, double y, double z)
        : v { x, y, z }
    {
    }

    double x() const { return v[0]; }
    double y() const { return v[1]; }
    double z() const { return v[2]; }

    double operator[](int i) const { return v[i]; }
    double& operator[](int i) { return v[i]; }

    vec3 operator-() const {
        return vec3(-v[0], -v[1], -v[2]);
    }

    vec3& operator+=(const vec3& v2) {
        v[0] += v2.v[0];
        v[1] += v2.v[1];
        v[2] += v2.v[2];
        return *this;
    }

    vec3& operator*=(const double s) {
        v[0] *= s;
        v[1] *= s;
        v[2] *= s;
        return *this;
    }

    vec3 operator/=(const double s) {
        return *this *= 1 / s;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    }

public:
    double v[3];
};

// Inlined member functions

inline vec3 operator+(const vec3& v1, const vec3& v2) {
    return vec3(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2) {
    return vec3(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2) {
    return vec3(v1.v[0] * v2.v[0], v1.v[1] * v2.v[1], v1.v[2] * v2.v[2]);
}

inline vec3 operator*(double s, const vec3& v1) {
    return vec3(s * v1.v[0], s * v1.v[1], s * v1.v[2]);
}

inline vec3 operator*(const vec3& v1, double s) {
    return s * v1;
}

inline vec3 operator/(vec3 v1, double s) {
    return (1 / s) * v1;
}

// Dot product
inline double dot(const vec3 &v1, const vec3 &v2) {
    return (v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2]);
}

// Cross product
inline vec3 cross(const vec3& v1, const vec3& v2) {
    return vec3(v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        v1.v[1] * v2.v[0] - v1.v[0] * v2.v[2],
        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]);
}

// Unit vector
inline vec3 unit(vec3 v1) {
    return v1 / v1.length();
}

#endif