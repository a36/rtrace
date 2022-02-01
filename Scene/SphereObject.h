#ifndef _SPHEREOBJECT_H
#define _SPHEREOBJECT_H

#include <Scene/Object.h>

class Ray;

// TODO
class SphereObject : public Object {
public:
    SphereObject() = default;
    SphereObject(f64 radius, Vec3 position);
    virtual ~SphereObject() = default;

    // Override this function
    bool intersect(Ray& r, f64& t1, f64& t2) override;

    inline const f64 radiusSqr() const { return m_radius * m_radius; }
    inline const f64 radius() const { return m_radius; }

private:
    f64 m_radius;
};

#endif