#include <Scene/SphereObject.h>

SphereObject::SphereObject(double r, Vec3 position)
    : m_radius(r)
{
    // Assign base class variable
    m_position = position;
}

bool SphereObject::intersect(Ray& r)
{
    return false;
}
