#ifndef _OBJECT_H
#define _OBJECT_H

#include <optional>

#include <Math/Vec3.h>

class Ray;

class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    // Override this function
    virtual bool intersect(Ray&) = 0;

private:
    Vec3 m_position;
};

#endif