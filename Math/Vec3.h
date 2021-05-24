#ifndef _VEC3_H
#define _VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class Vec3 {
public:
    Vec3();
    Vec3(double x, double y, double z);

    inline const double x() const;
    inline const double y() const;
    inline const double z() const;

    inline const double operator[](int i) const;
    inline double& operator[](int i);

    const Vec3 operator-() const;
    Vec3& operator+=(const Vec3& v2);
    Vec3& operator*=(const double s);
    Vec3 operator/=(const double s);

    const double length() const;
    const double length_squared() const;

    static inline double dot(const Vec3& v1, const Vec3& v2);
    static inline Vec3 cross(const Vec3& v1, const Vec3& v2);
    static inline Vec3 unit(Vec3& v1);

public:
    double v[3];
};

// Inlined member functions

inline Vec3 operator+(const Vec3& v1, const Vec3& v2);
inline Vec3 operator-(const Vec3& v1, const Vec3& v2);
inline Vec3 operator*(const Vec3& v1, const Vec3& v2);
inline Vec3 operator*(double s, const Vec3& v1);
inline Vec3 operator*(const Vec3& v1, double s);
inline Vec3 operator/(Vec3 v1, double s);

#endif