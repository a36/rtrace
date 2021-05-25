#ifndef _RAY_H
#define _RAY_H

#include <optional>

#include <Math/Vec3.h>
#include <Scene/Object.h>

class Ray {
public:
    Ray();
    Ray(Vec3 origin, Vec3 direction);

    inline const Vec3& getOrigin() const { return m_origin; }
    inline const Vec3& getDirection() const { return m_direction; }

    Object* getIntersection() { return m_intersect; }
    const Object* getIntersection() const { return m_intersect; }

private:
    Vec3 m_origin;
    Vec3 m_direction;

    Object* m_intersect = nullptr;
};

#endif