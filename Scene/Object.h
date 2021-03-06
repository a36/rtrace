#ifndef _OBJECT_H
#define _OBJECT_H

#include <Math/Vec3.h>

class Ray;

class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    // Override this function
    virtual bool intersect(Ray& r, f64& t1, f64& t2) = 0;

    inline Vec3& position() { return m_position; }
    inline const Vec3& position() const { return m_position; }

protected:
    Vec3 m_position;
};

#endif