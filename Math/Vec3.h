#ifndef _VEC3_H
#define _VEC3_H

#include <cmath>
#include <iostream>

#include <Types.h>

class Vec3 {
public:
    Vec3();
    Vec3(f64 x, f64 y, f64 z);

    inline const f64 x() const { return v[0]; };
    inline f64 x() { return v[0]; };
    inline const f64 y() const { return v[1]; };
    inline f64 y() { return v[1]; };
    inline const f64 z() const { return v[2]; };
    inline f64 z() { return v[2]; };

    const f64 operator[](int i) const;
    f64& operator[](int i);

    const Vec3 operator-() const;
    Vec3& operator+=(const Vec3& v2);
    Vec3& operator*=(const f64 s);
    Vec3 operator/=(const f64 s);

    Vec3& normalise();

    const f64 length() const;
    const f64 length_squared() const;

    static f64 dot(const Vec3& v1, const Vec3& v2);
    static Vec3 cross(const Vec3& v1, const Vec3& v2);
    static Vec3 unit(Vec3 v1);

public:
    f64 v[3];
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

inline Vec3 operator*(f64 s, const Vec3& v1)
{
    return Vec3(s * v1.v[0], s * v1.v[1], s * v1.v[2]);
}

inline Vec3 operator*(const Vec3& v1, f64 s)
{
    return s * v1;
}

inline Vec3 operator/(Vec3 v1, f64 s)
{
    return (1 / s) * v1;
}

#endif