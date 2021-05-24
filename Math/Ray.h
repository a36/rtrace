#ifndef _RAY_H
#define _RAY_H

#include <optional>

#include <Math/Vec3.h>

class Object;

class Ray {
public:
    Ray();
    Ray(Vec3 origin, Vec3 direction);

    inline const Vec3& getOrigin() const { return m_origin; }
    inline const Vec3& getDirection() const { return m_direction; }

private:
    Vec3 m_origin;
    Vec3 m_direction;

    std::optional<Object> m_intersect;
};

#endif