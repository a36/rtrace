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

    inline const double radiusSqr() const { return m_radius * m_radius; }
    inline const double radius() const { return m_radius; }
private:
    double m_radius;
};

#endif