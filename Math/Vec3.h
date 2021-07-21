#ifndef _VEC3_H
#define _VEC3_H

#include <cmath>
#include <iostream>

class Vec3 {
public:
    Vec3();
    Vec3(double x, double y, double z);

    inline const double x() const { return v[0]; };
    inline const double y() const { return v[1]; };
    inline const double z() const { return v[2]; };

    const double operator[](int i) const;
    double& operator[](int i);

    const Vec3 operator-() const;
    Vec3& operator+=(const Vec3& v2);
    Vec3& operator*=(const double s);
    Vec3 operator/=(const double s);

    Vec3& normalise();

    const double length() const;
    const double length_squared() const;

    static double dot(const Vec3& v1, const Vec3& v2);
    static Vec3 cross(const Vec3& v1, const Vec3& v2);
    static Vec3 unit(Vec3 v1);

public:
    double v[3];
};

// Inlined member functions
inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2]);
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2]);
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.v[0] * v2.v[0], v1.v[1] * v2.v[1], v1.v[2] * v2.v[2]);
}

inline Vec3 operator*(double s, const Vec3& v1)
{
    return Vec3(s * v1.v[0], s * v1.v[1], s * v1.v[2]);
}

inline Vec3 operator*(const Vec3& v1, double s)
{
    return s * v1;
}

inline Vec3 operator/(Vec3 v1, double s)
{
    return (1 / s) * v1;
}

#endif