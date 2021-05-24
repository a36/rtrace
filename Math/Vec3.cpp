#include <Math/Vec3.h>

Vec3::Vec3()
    : v { 0, 0, 0 }
{
}

Vec3::Vec3(double x, double y, double z)
    : v { x, y, z }
{
}

const double Vec3::operator[](int i) const
{
    return v[i];
}

double& Vec3::operator[](int i)
{
    return v[i];
}

const Vec3 Vec3::operator-() const
{
    return Vec3(-v[0], -v[1], -v[2]);
}

Vec3& Vec3::operator+=(const Vec3& v2)
{
    v[0] += v2.v[0];
    v[1] += v2.v[1];
    v[2] += v2.v[2];
    return *this;
}

Vec3& Vec3::operator*=(const double s)
{
    v[0] *= s;
    v[1] *= s;
    v[2] *= s;
    return *this;
}

Vec3 Vec3::operator/=(const double s)
{
    return *this *= 1 / s;
}

Vec3& Vec3::normalise()
{
    return *this = *this * sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

const double Vec3::length() const
{
    return sqrt(length_squared());
}

const double Vec3::length_squared() const
{
    return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

double Vec3::dot(const Vec3& v1, const Vec3& v2)
{
    return (v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2]);
}

Vec3 Vec3::cross(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        v1.v[1] * v2.v[0] - v1.v[0] * v2.v[2],
        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]);
}

Vec3 Vec3::unit(Vec3& v1)
{
    return v1 / v1.length();
}
