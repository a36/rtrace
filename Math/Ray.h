#ifndef _RAY_H
#define _RAY_H

#include <optional>

#include <Math/Vec3.h>
#include <Scene/Object.h>

class Ray {
public:
    Ray() = default;
    Ray(Vec3 origin, Vec3 direction);
    ~Ray() = default;

    inline const Vec3& getOrigin() const { return m_origin; }
    inline const Vec3& getDirection() const { return m_direction; }

    inline Object* getIntersection() { return m_intersect; }
    inline const Object* getIntersection() const { return m_intersect; }

private:
    Vec3 m_origin = {0, 0, 0};
    Vec3 m_direction = {0, 0, -1};

    Object* m_intersect = nullptr;
};

#endif