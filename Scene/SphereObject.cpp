#include <Scene/SphereObject.h>
#include <Math/Ray.h>

SphereObject::SphereObject(double r, Vec3 position)
    : m_radius(r)
{
    // Assign base class variable
    m_position = position;
}

bool SphereObject::intersect(Ray r)
{
    Vec3 oc = m_position - r.getOrigin();

    double a = Vec3::dot(oc, r.getDirection());
    if (a < 0)
        return false;

    double b = Vec3::dot(oc, oc) - a*a;
    if (b > radiusSqr())
        return false;

    double c = sqrt(m_radius * m_radius - b); // Will use c in World.cpp to calculate distance

    return true;
}
