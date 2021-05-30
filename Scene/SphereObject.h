#ifndef _SPHEREOBJECT_H
#define _SPHEREOBJECT_H

#include <Scene/Object.h>

class Ray;

// TODO
class SphereObject : public Object {
public:
    SphereObject() = default;
    SphereObject(double radius, Vec3 position);
    virtual ~SphereObject() = default;

    // Override this function
    bool intersect(Ray r) override;

private:
    double m_radius;
};

#endif